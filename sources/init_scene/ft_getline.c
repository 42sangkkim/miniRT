/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:34:50 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/05 16:28:32 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	20
#endif//BUFFER_SIZE

static int	read_buffer(char *buffer, int fd);
static int	append_buffer(char **line_ptr, char *buffer);
static int	save_buffer(char *line, char *buffer);

//	return value
//	1 : eol, read nothing
//	0 : read one line
//	-1 : error (read or malloc)
int	ft_getline(char **line_ptr, int fd)
{
	int				err;
	static char		buffer[BUFFER_SIZE + 1];

	*line_ptr = ft_strdup(buffer);
	if (*line_ptr == NULL)
	{
		printf("Error\nmalloc error\n");
		return (MALLOC_ERROR);
	}
	err = 0;
	while (err == 0 && ft_strchr(*line_ptr, '\n') == NULL)
	{
		err = read_buffer(buffer, fd);
		if (err == 0)
			err = append_buffer(line_ptr, buffer);
	}
	if (err >= 0)
		err = save_buffer(*line_ptr, buffer);
	if (err != 0)
	{
		free(*line_ptr);
		*line_ptr = NULL;
	}
	return (err);
}

static int	read_buffer(char *buffer, int fd)
{
	ssize_t	read_len;

	read_len = read(fd, buffer, BUFFER_SIZE);
	if (read_len < 0)
	{
		buffer[0] = '\0';
		return (perror("Error\n[perror]"), -1);
	}
	buffer[read_len] = '\0';
	if (read_len == 0)
		return (1);
	else
		return (0);
}

static int	append_buffer(char **line_ptr, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*line_ptr, buffer);
	*line_ptr = temp;
	if (temp == NULL)
		return (perror("Error\n[perror]"), -1);
	return (0);
}

static int	save_buffer(char *line, char *buffer)
{
	char	*nl_ptr;

	if (ft_strlen(line) == 0)
		return (1);
	nl_ptr = ft_strchr(line, '\n');
	if (nl_ptr != NULL)
		ft_strlcpy(buffer, nl_ptr + 1, BUFFER_SIZE + 1);
	nl_ptr[0] == '\0';
	return (0);
}
