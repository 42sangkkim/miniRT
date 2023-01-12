/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:17:02 by sangkkim          #+#    #+#             */
/*   Updated: 2023/01/12 22:00:31 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "color.h"

typedef union u_img_data_addr	t_img_data_addr;
typedef struct s_image			t_image;

union u_img_data_addr
{
	char				*raw;
	t_color				*color;
};

struct s_image
{
	void				*img_ptr;
	t_img_data_addr		data_addr;
};

#endif//IMAGE_H
