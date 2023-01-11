/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:52:51 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 00:04:55 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define BUFFER_SIZE			1024

# include <stddef.h>

typedef struct s_parser			t_parser;

typedef enum e_parser_status	t_parser_status;
enum e_parser_status
{
	ok = 0,
	invalid_word,
	end_of_file,
	error_open,
	error_read,
};

struct s_parser
{
	const char					*filename;
	int							fd;
	t_parser_status				status;
	int							read_all;
	size_t						line_number;
	size_t						line_index;
	char						*data;
	char						buffer[BUFFER_SIZE];
};

// parser1.c
t_parser	*parser_create(const char *filename);
void		parser_delete(t_parser *parser);
void		parser_read(t_parser *parser);
void		parser_print_error(t_parser *parser, const char *error_msg);

// parser2.c
void		parser_skip_space(t_parser *parser);
void		parser_skip_line(t_parser *parser);
void		parser_skip_len(t_parser *parser, size_t len);
void		parser_find_word(t_parser *parser);

#endif//PARSER_H
