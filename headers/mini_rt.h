/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:22:48 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 22:00:16 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# define SCREEN_WIDTH				1920
# define SCREEN_HEIGHT				1080
# define SCREEN_TITLE				"miniRT"

# include "scene.h"
# include "image.h"

typedef struct s_mini_rt			t_mini_rt;

struct s_mini_rt
{
	void							*mlx_ptr;
	void							*win_ptr;
	t_scene							scene;
	t_image							image;
};


#endif//MINI_RT_H
