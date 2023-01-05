/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:57:19 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/05 14:57:45 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>

static int	todigit(char c, int base);
static long	update_value(long value, char c, int base, long sign);

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int		sign;
	long	value;

	value = 0;
	if (base != 2 && base != 8 && base != 10 && base != 16)
	{
		*endptr = (char *)nptr;
		return (value);
	}
	if (*nptr == '-')
		sign = -1;
	else
		sign = 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (todigit(*nptr, base) >= 0)
	{
		value = update_value(value, *nptr++, base, sign);
		if (value == LONG_MAX || value == LONG_MIN)
			break ;
	}
	while (todigit(*nptr, base) >= 0)
		nptr++;
	*endptr = (char *)nptr;
	return (value);
}

static int	todigit(char c, int base)
{
	if (base == 2 || base == 8 || base == 10)
	{
		if ('0' <= c && c < '0' + base)
			return (c - '0');
	}
	else if (base == 16)
	{
		if ('0' <= c && c <= '9')
			return (c - '0');
		else if ('a' <= c && c <= 'f')
			return (c - 'a');
		else if ('A' <= c && c <= 'F')
			return (c - 'A');
	}
	return (-1);
}

static long	update_value(long value, char c, int base, long sign)
{
	long	digit;

	digit = (long)sign * todigit(c, base);
	if (value > LONG_MAX / base \
		|| (value == LONG_MAX / base && digit == LONG_MAX % base))
		return (LONG_MAX);
	else if (value < LONG_MIN / base \
		|| (value == LONG_MIN / base && digit == LONG_MIN % base))
		return (LONG_MIN);
	else
		return (value * base + digit);
}
