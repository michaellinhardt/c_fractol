/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_img_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:11:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/17 04:09:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

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
			if (i->anim_id == FADE_IN && i->fade > 0)
			{
				printf("fade: %d\n", i->fade);
				i->fade -= i->anim_tempo;
				if (i->fade < 0)
					i->fade = 0;
				i->str[(y * i->width + x) * 4 + 3] = i->fade;
			}
			i->str[(y * i->width + x) * 4 + 3] = 200;
			layer[++(l->i)] = img[y * i->width + x];
		}
		l->i = l->i - i->width + WIN_X;
	}
}

void		scene_img_push(t_data *d, t_dmlx *m, int i, t_img *img)
{
	img = layer(1);
	while ( m->scene_img[m->scene][++i].img )
		layer_add(img, &m->scene_img[m->scene][i]);
	(void)d;
}
