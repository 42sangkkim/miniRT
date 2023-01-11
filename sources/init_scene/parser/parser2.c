/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:14:38 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 00:04:51 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser_skip_space(t_parser *parser)
{
	size_t		temp_index;

	while (parser->status == ok)
	{
		temp_index = 0;
		while (parser->data[temp_index] == ' ' \
			|| parser->data[temp_index] == '\t')
			temp_index++;
		parser->line_index += temp_index;
		parser->data += temp_index;
		if (*parser->data == '\0' && parser->read_all == 1)
			parser->status = end_of_file;
		else if (*parser->data == '\0')
			parser_read(parser);
		else
			break ;
	}
}

void	parser_skip_line(t_parser *parser)
{
	size_t		temp_index;

	while (parser->status == ok)
	{
		temp_index = 0;
		while (parser->data[temp_index] != '\0' \
			&& parser->data[temp_index] != '\n')
				temp_index++;
		parser->line_index += temp_index;
		parser->data += temp_index;
		if (*parser->data == '\0')
		{
			if (parser->read_all == 1)
				parser->status = end_of_file;
			else
				parser_read(parser);
		}
		else if (*parser->data != '\n')
		{
			parser->line_number += 1;
			parser->line_index = 0;
			parser->data += 1;
			break ;
		}
	}
}

void	parser_skip_len(t_parser *parser, size_t len)
{
	size_t		temp_index;

	while (parser->status == ok)
	{
		temp_index = 0;
		while (parser->data[temp_index] != '\0' && temp_index < len)
			temp_index++;
		parser->line_index += temp_index;
		parser->data += temp_index;
		if (*parser->data == '\0' && parser->read_all == 1)
			parser->status = end_of_file;
		else if (temp_index < len)
		{
			len -= temp_index;
			parser_read(parser);
		}
		else
			break ;
	}
}

void	parser_find_word(t_parser *parser)
{
	size_t	temp_index;

	parser_skip_space(parser);
	if (parser->status == ok)
		parser_read(parser);
	if (parser->status == ok)
	{
		if (ft_strchr(parser->data, " ") == NULL \
			&& ft_strchr(parser->data, "\t") == NULL \
			&& ft_strchr(parser->data, "\n") == NULL)
			parser_print_error(parser, "too long word");
	}
}
