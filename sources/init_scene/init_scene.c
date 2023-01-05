/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:15:53 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/05 15:49:27 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "scene.h"
#include "error.h"
#include "libft.h"

// parse_scene.c
int	parse_ambient_light(\
	t_scene *scene, char *line, char *filename, size_t line_number);
int	parse_camera(\
	t_scene *scene, char *line, char *filename, size_t line_number);
int	parse_light(\
	t_scene *scene, char *line, char *filename, size_t line_number);

// parse_object.c
int	parse_sphere(\
	t_scene *scene, char *line, char *filename, size_t line_number);
int	parse_plane(\
	t_scene *scene, char *line, char *filename, size_t line_number);
int	parse_cylinder(\
	t_scene *scene, char *line, char *filename, size_t line_number);

// init_scene.c [here]
int	open_file(int *fd_ptr, int argc, char *argv[]);
int	parse_line(t_scene *scene, char *line, char *filename, size_t line_number);

int	get_next_line(char **line_ptr, int fd);

int	init_scene(t_scene *scene, int argc, char *argv[])
{
	int			err;
	int			fd;
	char		*line;
	size_t		line_number;

	ft_memset(scene, 0, sizeof(t_scene));
	err = open_file(&fd, argc, argv);
	line_number = 0;
	while (err == 0)
	{
		err = ft_getline(&line, fd);
		if (err == 1) // EOF
			return (0);
		line_number++;
		if (err == 0)
			err = parse_line(scene, line, argv[1], line_number);
		free(line);
	}
	return (err);
}

int	open_file(int *fd_ptr, int argc, char *argv[])
{
	char	*extension;

	if (argc != 2)
	{
		printf("Error\ninvalid argument\n");
		return (INVALID_ARGUMENT);
	}
	extension = ft_strrchr(argv[1], '.');
	if (extension == NULL || ft_strcmp(extension, ".rt") != 0)
	{
		printf("Error\n%s: invalid filename\n", argv[1]);
		return (INVALID_ARGUMENT);
	}
	*fd_ptr = open(argv[1], O_RDONLY);
	if (*fd_ptr == -1)
	{
		printf("Error\n%s: file doesn't exist\n", argv[1]);
		return (INVALID_ARGUMENT);
	}
	return (0);
}

int	parse_line(t_scene *scene, char *line, char *filename, size_t line_number)
{
	size_t		idx;

	idx = 0;
	while (line[idx] == ' ')
		idx++;
	if (line[idx] == '\0')
		return (0);
	else if (ft_strncmp(line[idx], "A ", 2) == 0)
		return (parse_ambient_light(scene, line, filename, line_number));
	else if (ft_strncmp(line[idx], "C ", 2) == 0)
		return (parse_camera(scene, line, filename, line_number));
	else if (ft_strncmp(line[idx], "L ", 2) == 0)
		return (parse_light(scene, line, filename, line_number));
	else if (ft_strncmp(line[idx], "sp ", 3) == 0)
		return (parse_sphere(scene, line, filename, line_number));
	else if (ft_strncmp(line[idx], "pl ", 3) == 0)
		return (parse_plane(scene, line, filename, line_number));
	else if (ft_strncmp(line[idx], "cy ", 3) == 0)
		return (parse_cylinder(scene, line, filename, line_number));
	else
	{
		printf("Error\n%s:%zu:%zu: invalid specifier", \
			filename, line_number, idx);
		return (INVALID_FILE);
	}
}
