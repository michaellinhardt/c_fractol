/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_layer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:11:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/15 06:19:07 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void		reset_img(t_img *img)
{
	int		*ptr;

	img->i = -1;
	ptr = (int *)img->str;
	while (++img->i < WIN_X * WIN_Y)
		ptr[img->i] = 0xFF000000;
}

void			layer_add(t_img *l, t_img *i)
{
	int		*layer;
	int		*img;
	int		x;
	int		y;

	layer = (int *)l->str;
	img = (int *)i->str;

	l->i = (i->top[0] * i->top[1] + i->top[0]) - 1;
	y = -1;
	while (++y < i->heigh)
	{
		x = -1;
		while (++x < i->width)
		{
			layer[++(l->i)] = img[y * i->width + x];
			l->str[l->i * 4 + 3] = i->fade;
		}
		l->i = l->i - i->width + WIN_X;
	}
}

t_img			*layer(int reset)
{
	static t_img	l;
	static int		init = 0;

	if (!init && ++init)
	{
		ft_bzero(&l, sizeof(t_img));
		l.img = mlx_new_img(&data()->mlx, &data()->mlx.layer, WIN_X, WIN_Y);
		l.str = mlx_get_data_addr(l.img, &l.bpp, &l.sl, &l.end);
		l.top[0] = 0;
		l.top[1] = 0;
		l.bot[0] = WIN_X;
		l.bot[1] = WIN_Y;
	}
	if (reset)
		reset_img(&l);
	return (&l);
}
