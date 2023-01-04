/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:30:50 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/02 18:50:16 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "point.h"
# include "color.h"

typedef struct s_object_list	t_object_list;

typedef struct s_object			t_object;

typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;

struct s_sphere
{
	t_point3					position;
	double						diameter;
	t_color						color;
};

struct s_plane
{
	t_point3					position;
	t_point3					orientation;
	t_color						color;
};

struct s_cylinder
{
	t_point3					position;
	t_point3					orientation;
	double						diameter;
	double						height;
	t_color						color;
};

struct s_object
{
	enum e_object_type
	{
		none = 0,
		sphere,
		plane,
		cylinder,
	}							type;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
};

struct s_object_list
{
	t_object		object;
	t_object_list	*next;
};

#endif//OBJECT_H
