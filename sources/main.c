/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:08:05 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/02 18:43:44 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	init_scene(t_scene *scene, int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int			err;
	t_scene		scene;
	// t_graphic	graphic;

	err = init_scene(&scene, argc, argv);
	// if (err == 0)
	// 	err = init_graphic(&graphic, &scene);
	// if (err == 0)
	// 	err = mlx_loop(graphic.mlx_ptr);
	return (err);
}
