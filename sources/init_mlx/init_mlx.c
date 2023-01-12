/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:51:37 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 10:53:34 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <mlx.h>
#include "graphics.h"
#include "scene.h"
#include "error.h"

static int	create_mlx(t_graphics *graphics);

int	init_mlx(t_graphics *graphics, t_scene *scene)
{
	int		err;

	(void)graphics;
	(void)scene;
	err = 0;
	err = create_mlx(graphics);
	return (err);
}

static int	create_mlx(t_graphics *graphics)
{
	graphics->mlx_ptr = mlx_init();
	if (graphics->mlx_ptr == NULL)
		return (MLX_ERROR);
	graphics->win_ptr = mlx_new_window(graphics->mlx_ptr, \
		SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	if (graphics->win_ptr == NULL)
		return (MLX_ERROR);
	graphics->img_ptr = mlx_new_image(graphics->mlx_ptr, \
		SCREEN_WIDTH, SCREEN_HEIGHT);
	if (graphics->img_ptr == NULL)
		return (MLX_ERROR);
	return (0);
}
