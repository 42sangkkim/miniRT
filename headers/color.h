/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:46:57 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/02 17:35:14 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef union u_color		t_color;

union u_color
{
	int			raw;
	struct
	{
		unsigned char	r;
		unsigned char	g;
		unsigned char	b;
		unsigned char	a;
	};
};

#endif//COLOR_H
