/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:34:50 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/03 23:24:48 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	20
#endif//BUFFER_SIZE

static int	append_buffer(char **line_ptr, char *prev, char *buffer, ssize_t size);

//	return value
//	1 : read one line
//	0 : eol
//	-1 : error (read ro malloc)
int	get_next_line(char **line_ptr, int fd)
{
	int				status;
	ssize_t			read_size;
	char			*nl_ptr;
	static char		buffer[BUFFER_SIZE + 1];

	*line_ptr = strdup(buffer); // TODO
	status = 1;
	while (status > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		status = append_buffer(line_ptr, *line_ptr, buffer, read_size);
		if (read_size > 0 && strchr(*line_ptr, '\n') != NULL) // TODO
			continue ;
	}
	if (status <= 0)
		return (status);
	nl_ptr = strchr(*line_ptr, '\n'); // TODO
	if (nl_ptr == NULL || nl_ptr[1] == '\0')
		return (status);
	strcpy(buffer, nl_ptr + 1); // TODO
	nl_ptr[1] = '\0';
	return (status);
}

static int	append_buffer(char **line_ptr, char *prev, char *buffer, ssize_t size)
{
	char	*temp;

	if (size <= 0)
	{
		buffer[0] = '\0';
		return (size);
	}
	temp = malloc((strlen(prev) + size + 1) * sizeof(char)); // TODO
	if (temp == NULL)
	{
		buffer[0] = '\0';
		return (-1);
	}
	buffer[size] = '\0';
	strcpy(strcpy(temp, prev) + strlen(prev), buffer); // TODO
	free(prev);
	*line_ptr = temp;
	buffer[0] = '\0';
	return (1);
}
