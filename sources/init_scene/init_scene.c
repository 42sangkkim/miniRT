/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:15:53 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/03 23:25:09 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "scene.h"
#include "error.h"

// parse_scene.c
int	parse_ambient_light(t_scene *scene, char **infos);
int	parse_camera(t_scene *scene, char **infos);
int	parse_light(t_scene *scene, char **infos);

// parse_object.c
int	parse_sphere(t_scene *scene, char **infos);
int	parse_plane(t_scene *scene, char **infos);
int	parse_cylinder(t_scene *scene, char **infos);

// init_scene.c [here]
int	is_valid_argument(int argc, char *argv[]);
int	parse_line(t_scene *scene, char **infos);
char	**ft_split(const char *str);

#include <string.h>
#include <stdio.h>

int	get_next_line(char **line_ptr, int fd);

#include <string.h>
int	init_scene(t_scene *scene, int argc, char *argv[])
{
	int			err;
	int			fd;
	char		*line;
	char		**infos;
	int			line_number;

	if (!is_valid_argument(argc, argv))
		return (INVALID_ARGUMENT);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (FILE_ERROR);
	memset(scene, 0, sizeof(t_scene));
	err = 0;
	line_number = 1;
	while (err == 0)
	{
		err = get_next_line(&line, fd);
		if (err != 0 || line == NULL)
			break ;
		printf(">>%s", line);
		infos = ft_split(line);
		if (infos != NULL)
			err = parse_line(scene, infos);
		free(line);
		if (infos != NULL)
		{
			for (int i=0; infos[i] != NULL; i++)
				free(infos[i]);
			free(infos);
		}
		//free_array(infos);
		line_number++;
	}
	if (err != INVALID_FILE)
		printf("Error\n%s: %d: invalid format\n", argv[1], line_number); // TODO
	return (err);
}

int	is_valid_argument(int argc, char *argv[])
{
	char	*extension;

	if (argc != 2)
		return (0);
	extension = strrchr(argv[1], '.'); // TODO
	if (extension == NULL)
		return (0);
	if (strcmp(extension, ".rt") != 0) // TODO
		return (0);
	return (1);
}

#include <stdio.h>
int	parse_line(t_scene *scene, char **infos)
{
	int			err;

	printf(">%s\n", infos[0]);
	if (strcmp(infos[0], "A") == 0) // TODO
		err = parse_ambient_light(scene, infos);
	else if (strcmp(infos[0], "C") == 0) // TODO
		err = parse_camera(scene, infos);
	else if (strcmp(infos[0], "L") == 0) // TODO
		err = parse_light(scene, infos);
	else if (strcmp(infos[0], "sp") == 0) // TODO
		err = parse_sphere(scene, infos);
	else if (strcmp(infos[0], "pl") == 0) // TODO
		err = parse_plane(scene, infos);
	else if (strcmp(infos[0], "cy") == 0) // TODO
		err = parse_cylinder(scene, infos);
	else
		err = INVALID_FILE;
	return (err);
}

#include <ctype.h>
char	**ft_split(const char *str)
{
	char	**words;
	size_t	count;

	count = 1 - isspace(str[0]);
	for (size_t i = 1; i < strlen(str); i++)
	{
		if (isspace(str[i]) && !isspace(str[i]))
			count++;
	}
	words = calloc(count + 1, sizeof(char *));
	if (words == NULL)
		return (NULL);

	size_t	idx;
	size_t	len;

	count++;
	idx = 0;
	while (str[idx])
	{
		while (isspace(str[idx]))
			idx++;
		if (str[idx] == '\0')
			break ;
		len = 0;
		while (str[idx + len] != '\0' && !isspace(str[idx + len]))
			len++;
		words[count] = strndup(str + idx, len);
		if (words[count] == NULL)
		{
			count = 0;
			while (words[count] == NULL)
				free(words[count++]);
			free(words);
			return (NULL);
		}
		idx += len;
	}
	return (words);
}
