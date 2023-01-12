/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:43:41 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 03:04:24 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# define SCREEN_WIDTH				1920
# define SCREEN_HEIGHT				1080
# define SCREEN_TITLE				"miniRT"

# include "color.h"

typedef struct s_graphics			t_graphics;

struct s_graphics
{
	void							*mlx_ptr;
	void							*win_ptr;
	int								width;
	int								height;
	void							*img_ptr;
};

#endif//GRAPHICS_H
