/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_layer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:11:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/17 16:39:37 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void		reset_img(t_img *img, int reset)
{
	int		*ptr;
	int		color;

	if (reset == 1)
		color = 0xFF000000;
	else
		color = 0x00000000;
	img->i = -1;
	ptr = (int *)img->str;
	while (++img->i < WIN_X * WIN_Y)
		ptr[img->i] = color;
}

t_img			*layer(int id, int reset)
{
	static t_img	l[LAYER_MAX];

	if (id > LAYER_MAX - 1 || id < 0)
		return ((t_img *)NULL);
	if (!l[id].img)
	{
		ft_bzero(&l[id], sizeof(t_img));
		l[id].img = mlx_new_img(&data()->mlx, &l[id], WIN_X, WIN_Y);
		l[id].top[0] = 0;
		l[id].top[1] = 0;
		l[id].bot[0] = WIN_X;
		l[id].bot[1] = WIN_Y;
	}
	if (reset > 0)
		reset_img(&l[id], reset);
	return (&l[id]);
}
