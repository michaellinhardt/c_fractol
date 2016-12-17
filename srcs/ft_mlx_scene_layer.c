/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_layer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:11:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/17 04:12:37 by mlinhard         ###   ########.fr       */
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

t_img			*layer(int id, int reset)
{
	static t_img	l[LAYER_MAX];

	if (id > LAYER_MAX - 1 || id < 0)
		return ((t_img *)NULL);
	if (!l[id].img)
	{
		ft_bzero(&l[id], sizeof(t_img));
		l[id]->img = mlx_new_img(&data()->mlx, &data()->mlx.layer, WIN_X, WIN_Y);
		l[id]->str = mlx_get_data_addr(l[id]->img, &l[id]->bpp, &l[id]->sl, &l[id]->end);
		l[id]->top[0] = 0;
		l[id]->top[1] = 0;
		l[id]->bot[0] = WIN_X;
		l[id]->bot[1] = WIN_Y;
	}
	if (reset)
		reset_img(&l);
	return (&l);
}
