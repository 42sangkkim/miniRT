/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:07:25 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/03 16:54:59 by sangkkim         ###   ########seoul.kr  */
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

int	parse_ambient_light(t_scene *scene, char **infos)
{
	int		err;

	if (scene->ambient_light != NULL)
		return (INVALID_FILE);
	if (info_length(infos) != 3)
		return (INVALID_FILE);
	scene->ambient_light = malloc(sizeof(t_ambient_light));
	if (scene->ambient_light == NULL)
		return (MALLOC_ERROR);
	err = parse_double_clamp(\
		&scene->ambient_light->brightness, infos[1], 0.0, 1.0);
	if (err == 0)
		err = parse_color(&scene->ambient_light->color, infos[2]);
	return (err);
}

int	parse_camera(t_scene *scene, char **infos)
{
	int		err;

	if (scene->camera != NULL)
		return (INVALID_FILE);
	if (info_length(infos) != 4)
		return (INVALID_FILE);
	scene->camera = malloc(sizeof(t_camera));
	if (scene->camera == NULL)
		return (MALLOC_ERROR);
	err = parse_point(&scene->camera->position, infos[1]);
	if (err == 0)
		err = parse_point(&scene->camera->orientation, infos[2]);
	if (err == 0)
		err = parse_double_clamp(&scene->camera->fov, infos[3], 0.0, 180.0);
	return (err);
}

int	parse_light(t_scene *scene, char **infos)
{
	int		err;

	if (scene->light != NULL)
		return (INVALID_FILE);
	if (info_length(infos) != 4)
		return (INVALID_FILE);
	scene->light = malloc(sizeof(t_light));
	if (scene->light == NULL)
		return (MALLOC_ERROR);
	err = parse_point(&scene->light->position, infos[1]);
	if (err == 0)
		err = parse_double_clamp(&scene->light->brightness, infos[2], 0.0, 1.0);
	if (err == 0)
		err = parse_color(&scene->light->color, infos[3]);
	return (err);
}
