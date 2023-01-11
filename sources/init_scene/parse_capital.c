/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_capital.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:21:31 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 00:41:09 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "parser.h"

long		parse_long_range(t_parser *parser, long min, long max);
double		parse_double_range(t_parser *parser, double min, double max);
t_point		parse_position(t_parser *parser);
t_point		parse_orientation(t_parser *parser);
t_color		parse_color(t_parser *parser);

static int	parse_ambient_light(t_scene *scene, t_parser *parser);
static int	parse_camera(t_scene *scene, t_parser *parser);
static int	parse_light(t_scene *scene, t_parser *parser);

int	parse_capital(t_scene *scene, t_parser *parser)
{
	int	err;

	if (ft_strncmp(parser->data, "A", 1) == 0)
		err = parse_ambient_light(scene, parser);
	else if (ft_strncmp(parser->data, "C", 1) == 0)
		err = parse_camera(scene, parser);
	else if (ft_strncmp(parser->data, "L", 1) == 0)
		err = parse_light(scene, parser);
	else
	{
		parser_print_error(parser, "Unknown identifier");
		err = FILE_FORMAT_ERROR;
	}
	if (err == 0)
		err = check_end_of_line(parser);
	return (err);
}

static int	parse_ambient_light(t_scene *scene, t_parser *parser)
{
	if (scene->ambient_light != NULL)
	{
		parser_print_error(parser, "Multiple ambient light detected");
		return (FILE_FORMAT_ERROR);
	}
	scene->ambient_light = ft_calloc(sizeof(t_ambient_light));
	if (scene->ambient_light == NULL)
		return (MALLOC_ERROR);
	if (parser->status == ok)
		scene->ambient_light->brightness = parse_double_range(parse, 0.0, 1.0);
	if (parser->status == ok)
		scene->ambient_light->color = parse_color(parser);
	return (0);
}

static int	parse_camera(t_scene *scene, t_parser *parser)
{
	if (scene->camera != NULL)
	{
		parser_print_error(parser, "Multiple camera detected");
		return (FILE_FORMAT_ERROR);
	}
	scene->camera = ft_calloc(sizeof(t_camera));
	if (scene->camera == NULL)
		return (MALLOC_ERROR);
	if (parser->status == ok)
		scene->camera->position = parse_position(parser);
	if (parser->status == ok)
		scene->camera->orientation = parse_orientation(parser);
	if (parser->status == ok)
		scene->camera->fov = parse_long_range(parser, 0, 180);
	return (0);
}

static int	parse_light(t_scene *scene, t_parser *parser)
{
	if (scene->light != NULL)
	{
		parser_print_error(parser, "Multiple light detected");
		return (FILE_FORMAT_ERROR);
	}
	scene->light = ft_calloc(sizeof(t_light));
	if (scene->light == NULL)
		return (MALLOC_ERROR);
	if (parser->status == ok)
		scene->light->position = parse_position(parser);
	if (parser->status == ok)
		scene->light->brightness = parse_double_range(parser, 0.0, 1.0);
	if (parser->status == ok)
		scene->light->color = parse_color(parser);
	return (0);
}
