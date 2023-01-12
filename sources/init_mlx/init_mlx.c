/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:51:37 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 20:29:04 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#define KEY_ESC				53

#include <stdlib.h>
#include <stddef.h>
#include <mlx.h>
#include "mini_rt.h"
#include "error.h"

static int	create_mlx(t_mini_rt *mini_rt);
static int	add_hooks(t_mini_rt *mini_rt);
void		draw_rainbow(t_mini_rt *mini_rt);

int	init_mlx(t_mini_rt *mini_rt)
{
	int		err;

	err = create_mlx(mini_rt);
	if (err == 0)
		err = add_hooks(mini_rt);
	if (err == 0)
		draw_rainbow(mini_rt);
	return (err);
}

static int	create_mlx(t_mini_rt *mini_rt)
{
	mini_rt->mlx_ptr = mlx_init();
	if (mini_rt->mlx_ptr == NULL)
		return (MLX_ERROR);
	mini_rt->win_ptr = mlx_new_window(mini_rt->mlx_ptr, \
		SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	if (mini_rt->win_ptr == NULL)
		return (MLX_ERROR);
	mini_rt->image.img_ptr = mlx_new_image(mini_rt->mlx_ptr, \
		SCREEN_WIDTH, SCREEN_HEIGHT);
	if (mini_rt->image.img_ptr == NULL)
		return (MLX_ERROR);
	mini_rt->image.data_addr.raw = mlx_get_data_addr(mini_rt->image.img_ptr, \
		&mini_rt->image.bits_per_pixel, &mini_rt->image.size_line, \
		&mini_rt->image.endian);
	if (mini_rt->image.data_addr.raw == NULL)
		return (MLX_ERROR);
	return (0);
}

int	leave_hook(void *param)
{
	(void)param;
	exit(0);
	return (1);
}

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == KEY_ESC)
		exit(0);
	return (keycode);
}

int	loop_hook(void *param)
{
	(void)param;
	return (0);
}

// void	destroy_scene(t_mini_rt *mini_rt)
// {
	
// }

void	draw_rainbow(t_mini_rt *mini_rt)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < SCREEN_WIDTH / 3)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			mini_rt->image.data_addr.color[y * SCREEN_WIDTH + x].r = 255;
			mini_rt->image.data_addr.color[y * SCREEN_WIDTH + x].g = 0;
			mini_rt->image.data_addr.color[y * SCREEN_WIDTH + x].b = 0;
			y++;
		}
		x++;
	}
	while (x < SCREEN_WIDTH / 3 * 2)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			mini_rt->image.data_addr.color[y * SCREEN_WIDTH + x].r = 0;
			mini_rt->image.data_addr.color[y * SCREEN_WIDTH + x].g = 255;
			mini_rt->image.data_addr.color[y * SCREEN_WIDTH + x].b = 0;
			y++;
		}
		x++;
	}
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			mini_rt->image.data_addr.color[y * SCREEN_WIDTH + x].r = 0;
			mini_rt->image.data_addr.color[y * SCREEN_WIDTH + x].g = 0;
			mini_rt->image.data_addr.color[y * SCREEN_WIDTH + x].b = 255;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mini_rt->mlx_ptr, mini_rt->win_ptr, \
		mini_rt->image.img_ptr, 0, 0);
}

void	check_leak(void)
{
	system("leaks miniRT");
}

static int	add_hooks(t_mini_rt *mini_rt)
{
	int		err;

	atexit(check_leak);
	err = mlx_hook(mini_rt->win_ptr, 17, 1, leave_hook, mini_rt);
	if (err == 0)
		err = mlx_key_hook(mini_rt->win_ptr, key_hook, mini_rt);
	if (err == 0)
		err = mlx_loop_hook(mini_rt->mlx_ptr, loop_hook, mini_rt);
	return (err);
}

