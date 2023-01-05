/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:09:57 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/05 14:59:45 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "point.h"
#include "color.h"
#include "object.h"
#include "error.h"
#include "libft.h"

#include <stdio.h>
int	info_length(char **infos)
{
	int	len;

	len = 0;
	while (infos[len] != NULL)
		len++;
	printf("info len : %d\n", (int)len);
	return (len);
}

#include <stdlib.h>
int	parse_double_clamp(double *ptr, char *str, double min, double max)
{
	double		value;

	value = strtod(str, &str); // TODO
	if (*str != '\0')
		return (INVALID_FILE);
	if (value < min || max < value)
		return (INVALID_FILE);
	*ptr = value;
	return (0);
}

int	parse_point(t_point3 *ptr, char *str)
{
	double		value;

	value = strtod(str, &str); // TODO
	if (*str != ',')
		return (INVALID_FILE);
	printf("double : %f\n", value);
	ptr->x = value;
	value = strtod(str, &str); // TODO
	if (*str != ',')
		return (INVALID_FILE);
	printf("double : %f\n", value);
	ptr->y = value;
	value = strtod(str, &str); // TODO
	if (*str != '\0')
		return (INVALID_FILE);
	printf("double : %f\n", value);
	ptr->z = value;
	return (0);
}

int	parse_color(t_color *ptr, char *str)
{
	long		value;
	char		*s_ptr;

	s_ptr = str;
	value = ft_strtol(str, &str, 10);
	if (*(str) != ',' || value < 0 || value > 255)
		return (INVALID_FILE);
	ptr->r = (unsigned char)value;
	value = ft_strtol(++str, &str, 10);
	if (*str != ',' || value < 0 || value > 255)
		return (INVALID_FILE);
	ptr->g = (unsigned char)value;
	value = ft_strtol(++str, &str, 10);
	if ((*str != '\0' && *str != '\n') || value < 0 || value > 255)
		return (INVALID_FILE);
	ptr->b = (unsigned char)value;
	return (0);
}

void	add_object_list(t_object_list **head_ptr, t_object_list *new)
{
	while (*head_ptr != NULL)
		head_ptr = &(*head_ptr)->next;
	*head_ptr = new;
}
