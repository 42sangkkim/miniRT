/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:10:09 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/03 16:55:34 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "point.h"
#include "color.h"
#include "object.h"
#include "scene.h"
#include "error.h"

// parse_utils.c
int		info_length(char **infos);
int		parse_double_clamp(double *ptr, char *str, double min, double max);
int		parse_point(t_point3 *ptr, char *str);
int		parse_color(t_color *ptr, char *str);
void	add_object_list(t_object_list **head_ptr, t_object_list *new);

int	parse_sphere(t_scene *scene, char **infos)
{
	t_object_list	*new_node;
	int				err;

	if (info_length(infos) != 4)
		return (INVALID_FILE);
	new_node = malloc(sizeof(t_object_list));
	if (new_node == NULL)
		return (MALLOC_ERROR);
	new_node->object.type = sphere;
	add_object_list(&scene->object_list, new_node);
	err = parse_point(&new_node->object.sphere.position, infos[1]);
	if (err == 0)
		err = parse_double_clamp(\
			&new_node->object.sphere.diameter, infos[2], 0., 0.);
	if (err == 0)
		err = parse_color(&new_node->object.sphere.color, infos[3]);
	return (err);
}

int	parse_plane(t_scene *scene, char **infos)
{
	t_object_list	*new_node;
	int				err;

	if (info_length(infos) != 4)
		return (INVALID_FILE);
	new_node = malloc(sizeof(t_object_list));
	if (new_node == NULL)
		return (MALLOC_ERROR);
	new_node->object.type = plane;
	add_object_list(&scene->object_list, new_node);
	err = parse_point(&new_node->object.plane.position, infos[1]);
	if (err == 0)
		err = parse_point(&new_node->object.plane.orientation, infos[2]);
	if (err == 0)
		err = parse_color(&new_node->object.plane.color, infos[3]);
	return (err);
}

int	parse_cylinder(t_scene *scene, char **infos)
{
	t_object_list	*new_node;
	int				err;

	if (info_length(infos) != 6)
		return (INVALID_FILE);
	new_node = malloc(sizeof(t_object_list));
	if (new_node == NULL)
		return (MALLOC_ERROR);
	new_node->object.type = cylinder;
	add_object_list(&scene->object_list, new_node);
	err = parse_point(&new_node->object.cylinder.position, infos[1]);
	if (err == 0)
		err = parse_point(&new_node->object.cylinder.orientation, infos[2]);
	if (err == 0)
		err = parse_double_clamp(\
			&new_node->object.cylinder.diameter, infos[3], 0., 0.);
	if (err == 0)
		err = parse_double_clamp(\
			&new_node->object.cylinder.height, infos[4], 0., 0.);
	if (err == 0)
		err = parse_color(&new_node->object.cylinder.color, infos[5]);
	return (err);
}
