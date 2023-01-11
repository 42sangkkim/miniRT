/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:45:29 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 00:46:12 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "parser.h"
#include "error.h"

int			parse_capital(t_scene *scene, t_parser *parser);
int			parse_object(t_scene *scene, t_parser *parser);

static void	parse_line(t_scene *scene, t_parser *parser);
static void	parse_element(t_scene *scene, t_parser *parser);

int	parse_rt_file(t_scene *scene, const char *filename)
{
	int			err;
	t_parser	*parser;

	parser = parser_create(filename);
	if (parser == NULL)
		return (MALLOC_ERROR);
	else if (parser->status == error_open)
		return (FILE_OPEN_ERROR);
	while (parser->status == ok)
	{
		if (*parser->data == '#')
			parser_skip_line(parser);
		else
			parse_line(scene, parser);
	}
	if (parser->status == invalid_word)
		err = FILE_FORMAT_ERROR;
	else if (parser->status == error_read)
		err = FILE_READ_ERROR;
	else
		err = 0;
	parser_delete(parser);
	return (err);
}

static void	parse_line(t_scene *scene, t_parser *parser)
{
	parser_skip_space(parser);
	if (parser->status != ok)
		return ;
	else if (*parser->data == '#' || *parser->data == '\n')
		parser_skip_line(parser);
	else
	{
		parser_read(parser);
		if (parser->status == ok)
			parse_element(scene, parser);
	}
}

static void	parse_element(t_scene *scene, t_parser *parser)
{
	if (isspace(parser->data[1]))
		err = parse_capital(scene, parser);
	else if (isspace(parser->data[2]))
		err = parse_object(scene, parser);
	else
	{
		parser_print_error(parser, "Unknown identifier");
		err = FILE_FORMAT_ERROR;
	}
	return (err);
}
