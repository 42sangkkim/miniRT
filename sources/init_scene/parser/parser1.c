/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:58:55 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 02:06:12 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "parser.h"

t_parser	*parser_create(const char *filename)
{
	t_parser	*parser;

	parser = ft_calloc(1, sizeof(t_parser));
	if (parser == NULL)
		return (NULL);
	parser->fd = open(filename, O_RDONLY);
	if (parser->fd == -1)
		parser->status = error_open;
	else
	{
		parser->filename = filename;
		parser->data = parser->buffer;
	}
	return (parser);
}

void	parser_delete(t_parser *parser)
{
	close(parser->fd);
	free(parser);
}

void	parser_read(t_parser *parser)
{
	size_t		data_len;
	ssize_t		read_len;

	data_len = ft_strlen(parser->data);
	if (data_len == BUFFER_SIZE)
		return ;
	ft_strlcpy(parser->buffer, parser->data, BUFFER_SIZE);
	parser->data = parser->buffer;
	read_len = read(\
		parser->fd, parser->buffer + data_len, BUFFER_SIZE - data_len);
	if (read_len == -1)
		parser->status = error_read;
	else if (read_len == 0)
		parser->read_all = 1;
	else
		parser->buffer[data_len + read_len] = '\0';
}

void	parser_print_error(t_parser *parser, const char *error_msg)
{
	parser->status = invalid_word;
	printf("Error\n%s:%zu:%zu: %s\n", \
		parser->filename, parser->line_number + 1, parser->line_index + 1, \
		error_msg);
}
