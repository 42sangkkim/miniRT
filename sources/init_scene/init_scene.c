/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:34:24 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 02:53:57 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "scene.h"
#include "error.h"

int			parse_rt_file(t_scene *scene, const char *filename);
void		print_scene(t_scene *scene);

static int	valid_extension(const char *filename);
static int	check_scene_validity(t_scene *scene);

int	init_scene(t_scene *scene, int argc, char *argv[])
{
	int	err;

	if (argc != 2 || !valid_extension(argv[1]))
		return (INVALID_ARGUMENT);
	err = parse_rt_file(scene, argv[1]);
	if (err == 0)
		err = check_scene_validity(scene);
	return (err);
}

static int	valid_extension(const char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (extension == NULL || ft_strcmp(extension, ".rt") != 0)
		return (0);
	return (1);
}

static int	check_scene_validity(t_scene *scene)
{
	if (scene->ambient_light == NULL)
	{
		printf("Error\nNo ambient light in file\n");
		return (FILE_FORMAT_ERROR);
	}
	if (scene->camera == NULL)
	{
		printf("Error\nNo camera in file\n");
		return (FILE_FORMAT_ERROR);
	}
	if (scene->light == NULL)
	{
		printf("Error\nNo light in file\n");
		return (FILE_FORMAT_ERROR);
	}
	if (scene->object_list == NULL)
		printf("Warning\nNo object in file\n");
	print_scene(scene);
	return (0);
}
