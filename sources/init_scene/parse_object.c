/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:40:08 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 02:18:27 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "parser.h"
#include "error.h"

int			check_end_of_line(t_parser *parser);
double		parse_double(t_parser *parser);
t_point		parse_position(t_parser *parser);
t_point		parse_orientation(t_parser *parser);
t_color		parse_color(t_parser *parser);

static int	parse_sphere(t_scene *scene, t_parser *parser);
static int	parse_plane(t_scene *scene, t_parser *parser);
static int	parse_cylinder(t_scene *scene, t_parser *parser);

int	parse_object(t_scene *scene, t_parser *parser)
{
	int	err;

	if (ft_strncmp(parser->data, "sp", 2) == 0)
		err = parse_sphere(scene, parser);
	else if (ft_strncmp(parser->data, "pl", 2) == 0)
		err = parse_plane(scene, parser);
	else if (ft_strncmp(parser->data, "cy", 2) == 0)
		err = parse_cylinder(scene, parser);
	else
	{
		parser_print_error(parser, "Unknown identifier");
		err = FILE_FORMAT_ERROR;
	}
	if (err == 0)
		err = check_end_of_line(parser);
	return (err);
}

static t_object_list	*add_new_object(t_scene *scene)
{
	t_object_list	**tail;
	t_object_list	*new_node;

	new_node = ft_calloc(1, sizeof(t_object_list));
	if (new_node == NULL)
		return (NULL);
	tail = &scene->object_list;
	while (*tail != NULL)
		tail = &(*tail)->next;
	*tail = new_node;
	return (new_node);
}

static int	parse_sphere(t_scene *scene, t_parser *parser)
{
	t_object_list	*object_node;

	object_node = add_new_object(scene);
	if (object_node == NULL)
		return (MALLOC_ERROR);
	object_node->object.type = sphere;
	parser_skip_len(parser, 2);
	if (parser->status == ok)
		object_node->object.sphere.position = parse_position(parser);
	if (parser->status == ok)
		object_node->object.sphere.diameter = parse_double(parser);
	if (parser->status == ok)
		object_node->object.sphere.color = parse_color(parser);
	return (0);
}

static int	parse_plane(t_scene *scene, t_parser *parser)
{
	t_object_list	*object_node;

	object_node = add_new_object(scene);
	if (object_node == NULL)
		return (MALLOC_ERROR);
	object_node->object.type = plane;
	parser_skip_len(parser, 2);
	if (parser->status == ok)
		object_node->object.plane.position = parse_position(parser);
	if (parser->status == ok)
		object_node->object.plane.orientation = parse_orientation(parser);
	if (parser->status == ok)
		object_node->object.plane.color = parse_color(parser);
	return (0);
}

static int	parse_cylinder(t_scene *scene, t_parser *parser)
{
	t_object_list	*object_node;

	object_node = add_new_object(scene);
	if (object_node == NULL)
		return (MALLOC_ERROR);
	object_node->object.type = cylinder;
	parser_skip_len(parser, 2);
	if (parser->status == ok)
		object_node->object.cylinder.position = parse_position(parser);
	if (parser->status == ok)
		object_node->object.cylinder.orientation = parse_orientation(parser);
	if (parser->status == ok)
		object_node->object.cylinder.diameter = parse_double(parser);
	if (parser->status == ok)
		object_node->object.cylinder.height = parse_double(parser);
	if (parser->status == ok)
		object_node->object.cylinder.color = parse_color(parser);
	return (0);
}
