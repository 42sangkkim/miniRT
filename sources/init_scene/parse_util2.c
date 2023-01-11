/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:00:53 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 02:10:48 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "point.h"
#include "color.h"
#include "parser.h"

t_point	parse_position(t_parser *parser)
{
	t_point	position;
	char	*endptr;

	ft_bzero(&position, sizeof(t_point));
	parser_find_word(parser);
	if (parser->status != ok)
		return (position);
	position.x = ft_strtod(parser->data, &endptr);
	if (*endptr == ',')
		position.y = ft_strtod(endptr + 1, &endptr);
	if (*endptr == ',')
		position.z = ft_strtod(endptr + 1, &endptr);
	if (ft_strchr(" \t\n", *endptr) == NULL)
		parser_print_error(parser, "Position format required");
	else if (ft_strnstr(parser->data, ",,", endptr - parser->data) != NULL)
		parser_print_error(parser, "Position format required");
	else
		parser_skip_len(parser, endptr - parser->data);
	return (position);
}

t_point	parse_orientation(t_parser *parser)
{
	t_point	orientation;
	char	*endptr;

	ft_bzero(&orientation, sizeof(t_point));
	parser_find_word(parser);
	if (parser->status != ok)
		return (orientation);
	orientation.x = ft_strtod(parser->data, &endptr);
	if (*endptr == ',')
		orientation.y = ft_strtod(endptr + 1, &endptr);
	if (*endptr == ',')
		orientation.z = ft_strtod(endptr + 1, &endptr);
	if (ft_strchr(" \t\n", *endptr) == NULL)
		parser_print_error(parser, "Orientation format required");
	else if (ft_strnstr(parser->data, ",,", endptr - parser->data) != NULL)
		parser_print_error(parser, "Orientation format required");
	else if (orientation.x < -1.0 || orientation.x > 1.0 \
		|| orientation.y < -1.0 || orientation.y > 1.0 \
		|| orientation.z < -1.0 || orientation.z > 1.0)
		parser_print_error(parser, "Orientation is out of range");
	else
		parser_skip_len(parser, endptr - parser->data);
	return (orientation);
}

t_color	parse_color(t_parser *parser)
{
	t_color	color;
	char	*endptr;

	ft_bzero(&color, sizeof(t_color));
	parser_find_word(parser);
	if (parser->status != ok)
		return (color);
	color.r = ft_strtol(parser->data, &endptr, 10);
	if (*endptr == ',')
		color.g = ft_strtol(endptr + 1, &endptr, 10);
	if (*endptr == ',')
		color.b = ft_strtol(endptr + 1, &endptr, 10);
	if (ft_strchr(" \t\n", *endptr) == NULL)
		parser_print_error(parser, "Color format required");
	else if (ft_strnstr(parser->data, ",,", endptr - parser->data) != NULL)
		parser_print_error(parser, "Color format required");
	else if (color.r < 0 || color.r > 255 \
		|| color.g < 0 || color.g > 255 \
		|| color.b < 0 || color.b > 255)
		parser_print_error(parser, "Color is out of range");
	else
		parser_skip_len(parser, endptr - parser->data);
	return (color);
}
