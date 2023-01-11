/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:25:54 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 01:56:22 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "error.h"

int	check_end_of_line(t_parser *parser)
{
	if (parser->status == ok)
		parser_skip_space(parser);
	if (parser->status == ok)
	{
		if (*parser->data == '#' || *parser->data == '\n')
			parser_skip_line(parser);
		else
			parser_print_error(parser, "Unknown information");
	}
	if (parser->status == invalid_word)
		return (FILE_FORMAT_ERROR);
	else if (parser->status == error_read)
		return (FILE_READ_ERROR);
	else
		return (0);
}

long	parse_long(t_parser *parser)
{
	long	value;
	char	*endptr;

	parser_find_word(parser);
	if (parser->status != ok)
		return (0);
	value = ft_strtol(parser->data, &endptr, 10);
	if (ft_strchr(" \t\n", *endptr) == NULL)
		parser_print_error(parser, "Long format required");
	else
		parser_skip_len(parser, endptr - parser->data);
	return (value);
}

long	parse_long_range(t_parser *parser, long min, long max)
{
	long	value;
	char	*endptr;

	parser_find_word(parser);
	if (parser->status != ok)
		return (0.0);
	value = ft_strtol(parser->data, &endptr, 10);
	if (ft_strchr(" \t\n", *endptr) == NULL)
		parser_print_error(parser, "Long format required");
	else if (value < min || value > max)
		parser_print_error(parser, "Value is out of range");
	else
		parser_skip_len(parser, endptr - parser->data);
	return (value);
}

double	parse_double(t_parser *parser)
{
	double	value;
	char	*endptr;

	parser_find_word(parser);
	if (parser->status != ok)
		return (0.0);
	value = ft_strtod(parser->data, &endptr);
	if (ft_strchr(" \t\n", *endptr) == NULL)
		parser_print_error(parser, "Double format required");
	else
		parser_skip_len(parser, endptr - parser->data);
	return (value);
}

double	parse_double_range(t_parser *parser, double min, double max)
{
	double	value;
	char	*endptr;

	parser_find_word(parser);
	if (parser->status != ok)
		return (0.0);
	value = ft_strtod(parser->data, &endptr);
	if (ft_strchr(" \t\n", *endptr) == NULL)
		parser_print_error(parser, "Double format required");
	else if (value < min || value > max)
		parser_print_error(parser, "Value is out of range");
	else
		parser_skip_len(parser, endptr - parser->data);
	return (value);
}
