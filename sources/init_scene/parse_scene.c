/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:07:25 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/05 16:41:02 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "point.h"
#include "color.h"
#include "object.h"
#include "scene.h"
#include "error.h"

int	info_length(char **infos);
int	parse_double_clamp(double *ptr, char *str, double min, double max);
int	parse_point(t_point3 *ptr, char *str);
int	parse_color(t_color *ptr, char *str);

int	parse_ambient_light(\
	t_scene *scene, char *line, char *filename, size_t line_number)
{
	size_t		idx;

	idx = 0;
	while (line[idx] == ' ')
		idx++;
	idx += 1; // skip "A"
	while (line[idx] == ' ')
		idx++;
	idx = (size_t)ft_strtod(&scene->ambient_light->brightness, line + idx) - \
		(size_t)line;
	if (line[idx] != ' ')
	{
		printf("Error\n%s:%zu:%zu: invalid format", filename, line_number, idx);
		return (FILE_ERROR);
	}
	while (line[idx] == ' ')
		idx++;
	idx = ()
}

int	parse_camera(\
	t_scene *scene, char *line, char *filename, size_t line_number);
int	parse_light(\
	t_scene *scene, char *line, char *filename, size_t line_number);