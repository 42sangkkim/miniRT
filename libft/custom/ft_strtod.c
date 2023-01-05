/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:26:00 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/04 16:52:25 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static double	get_minor_number(const char *nptr, const char **endptr);

double	ft_strtod(const char *nptr, char **endptr)
{
	int		sign;
	double	value;

	if (*nptr == '-')
		sign = -1;
	else
		sign = 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	value = 0;
	while ('0' <= *nptr && *nptr <= '9')
		value = value * 10 + (*nptr++ - '0');
	if (*nptr == '.')
	{
		nptr++;
		value += get_minor_number(nptr, &nptr);
	}
	*endptr = (char *)nptr;
	return ((double)sign * value);
}

static double	get_minor_number(const char *nptr, const char **endptr)
{
	double	digit_log;
	double	value;

	digit_log = 0.1;
	value = 0.;
	while ('0' <= *nptr && *nptr <= '9')
	{
		value = value + (*nptr++ - '0') * digit_log;
		digit_log /= 10;
		if (digit_log == 0.0)
			break ;
	}
	while ('0' <= *nptr && *nptr <= '9')
		nptr++;
	*endptr = (char *)nptr;
	return (value);
}
