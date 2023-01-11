/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:52:56 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 01:34:01 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "point.h"
# include "color.h"
# include "object.h"

typedef struct s_scene			t_scene;

typedef struct s_ambient_light	t_ambient_light;
typedef struct s_camera			t_camera;
typedef struct s_light			t_light;

struct s_scene
{
	t_ambient_light		*ambient_light;
	t_camera			*camera;
	t_light				*light;
	t_object_list		*object_list;
};

struct s_ambient_light
{
	double		brightness;
	t_color		color;
};

struct s_camera
{
	t_point		position;
	t_point		orientation;
	long		fov;
};

struct s_light
{
	t_point		position;
	double		brightness;
	t_color		color;
};

#endif//SCENE_H
