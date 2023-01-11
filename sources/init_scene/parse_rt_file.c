/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:45:29 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 02:37:53 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "parser.h"
#include "error.h"

int			parse_capital(t_scene *scene, t_parser *parser);
int			parse_object(t_scene *scene, t_parser *parser);

static int	parse_line(t_scene *scene, t_parser *parser);
static int	parse_element(t_scene *scene, t_parser *parser);

int	parse_rt_file(t_scene *scene, const char *filename)
{
	int			err;
	t_parser	*parser;

	parser = parser_create(filename);
	if (parser == NULL)
		return (MALLOC_ERROR);
	else if (parser->status == error_open)
		return (FILE_OPEN_ERROR);
	err = 0;
	while (err == 0 && parser->status == ok)
		err = parse_line(scene, parser);
	if (err == 0 && parser->status == invalid_word)
		err = FILE_FORMAT_ERROR;
	else if (err == 0 && parser->status == error_read)
		err = FILE_READ_ERROR;
	parser_delete(parser);
	return (err);
}

static int	parse_line(t_scene *scene, t_parser *parser)
{
	parser_skip_space(parser);
	if (parser->status != ok)
		return (0);
	else if (*parser->data == '#' || *parser->data == '\n')
		parser_skip_line(parser);
	else
	{
		parser_read(parser);
		if (parser->status == ok)
			return (parse_element(scene, parser));
	}
	return (0);
}

static int	parse_element(t_scene *scene, t_parser *parser)
{
	int		err;

	if (ft_isspace(parser->data[1]))
		err = parse_capital(scene, parser);
	else if (ft_isspace(parser->data[2]))
		err = parse_object(scene, parser);
	else
	{
		parser_print_error(parser, "Unknown identifier");
		err = FILE_FORMAT_ERROR;
	}
	return (err);
}
