/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:34:24 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 00:46:39 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"

static int	check_scene_validity(t_scene *scene);

int	init_scene(int argc, char *argv[], t_scene *scene)
{
	int	err;

	if (argc != 2 || !valid_extension(argv[1]))
		return (INVALID_ARGUMENT);
	ft_bzero(scene, sizeof(t_scene));
	err = parse_rt_file(scene, argv[1]);
	if (err == 0)
		err = check_scene_validity(scene);
	return (err);
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
	return (0);
}
