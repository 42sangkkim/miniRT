/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:08:05 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 10:53:20 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include "libft.h"
#include "scene.h"
#include "graphics.h"
#include "error.h"

int			init_scene(t_scene *scene, int argc, char *argv[]);
int			init_mlx(t_graphics *graphics, t_scene *scene);

static void	print_error(int err);

int	main(int argc, char *argv[])
{
	int			err;
	t_scene		scene;
	t_graphics	graphics;

	ft_bzero(&scene, sizeof(t_scene));
	ft_bzero(&graphics, sizeof(t_graphics));
	err = init_scene(&scene, argc, argv);
	if (err == 0)
		err = init_mlx(&graphics, &scene);
	if (err != 0)
		return (print_error(err), err);
	mlx_loop(graphics.mlx_ptr);
}

static void	print_error(int err)
{
	if (err == INVALID_ARGUMENT)
		printf("Error\nInvalid argument\n");
	else if (err == FILE_OPEN_ERROR)
		printf("Error\nFile open fail\n");
	else if (err == FILE_READ_ERROR)
		printf("Error\nFile read fail\n");
	else if (err == MALLOC_ERROR)
		printf("Error\nMalloc fail\n");
	else if (err == MLX_ERROR)
		printf("Error\nMLX fail\n");
}
