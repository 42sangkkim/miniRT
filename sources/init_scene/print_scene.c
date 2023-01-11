/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:31:59 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 02:40:12 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "scene.h"

static void	print_sphere(t_object_list *node)
{
	printf("SPHERE : \n\tposition : %f,%f,%f\n", \
		node->object.sphere.position.x, \
		node->object.sphere.position.y, \
		node->object.sphere.position.z);
	printf("\tdiameter : %f\n\tcolor : %u,%u,%u\n", \
		node->object.sphere.diameter, \
		node->object.sphere.color.r, \
		node->object.sphere.color.g, \
		node->object.sphere.color.b);
}

static void	print_plane(t_object_list *node)
{
	printf("PLANE : \n\tposition : %f,%f,%f\n", \
		node->object.plane.position.x, \
		node->object.plane.position.y, \
		node->object.plane.position.z);
	printf("\torientation : %f,%f,%f\n\tcolor : %u,%u,%u\n", \
		node->object.plane.orientation.x, \
		node->object.plane.orientation.y, \
		node->object.plane.orientation.z, \
		node->object.plane.color.r, \
		node->object.plane.color.g, \
		node->object.plane.color.b);
}

static void	print_cylinder(t_object_list *node)
{
	printf("CYLINDER : \n\tposition : %f,%f,%f\n", \
		node->object.cylinder.position.x, \
		node->object.cylinder.position.y, \
		node->object.cylinder.position.z);
	printf("\torientation : %f,%f,%f\n\tdiameter : %f\n", \
		node->object.cylinder.orientation.x, \
		node->object.cylinder.orientation.y, \
		node->object.cylinder.orientation.z, \
		node->object.cylinder.diameter);
	printf("\theight : %f\n\tcolor : %u,%u,%u\n", \
		node->object.cylinder.height, \
		node->object.cylinder.color.r, \
		node->object.cylinder.color.g, \
		node->object.cylinder.color.b);
}

void	print_scene(t_scene *scene)
{
	t_object_list	*node;

	printf("AMBIENT LIGHT :\n\tbrightness : %f\n\tcolor : %u,%u,%u\n", \
		scene->ambient_light->brightness, scene->ambient_light->color.r, \
		scene->ambient_light->color.g, scene->ambient_light->color.b);
	printf("CAMERA :\n\tposition : %f,%f,%f\n", scene->camera->position.x, \
		scene->camera->position.y, scene->camera->position.z);
	printf("\torientation : %f,%f,%f\n\tFOV : %ld\n", \
		scene->camera->orientation.x, scene->camera->orientation.y, \
		scene->camera->orientation.z, scene->camera->fov);
	printf("LIGHT :\n\tposition : %f,%f,%f\n", scene->light->position.x, \
		scene->light->position.y, scene->light->position.z);
	printf("\tbrightness : %f\n\tcolor : %u,%u,%u\n", scene->light->brightness, \
		scene->light->color.r, scene->light->color.g, scene->light->color.b);
	node = scene->object_list;
	while (node != NULL)
	{
		if (node->object.type == sphere)
			print_sphere(node);
		else if (node->object.type == plane)
			print_plane(node);
		else if (node->object.type == cylinder)
			print_cylinder(node);
		node = node->next;
	}
}
