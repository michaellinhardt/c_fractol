/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1_fractol_draw2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:40:00 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/28 02:52:28 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	put_pixel(t_img *lay, t_fract *param, t_fract *f)
{
	if (f->ite >= param->itemin && f->ite <= param->itemax)
		lay->ptr[f->i] = 0x00000000 + (f->ite * 1000);
	else
		lay->ptr[f->i] = 0x00000000 + (f->ite * 10);
}

void		scene_1_draw_bonus1(t_img *lay, t_fract *param, t_fract *f)
{
	f->pos.r = f->i % data()->mlx.winx;
	f->pos.i = f->i / data()->mlx.winx;
	f->z.r = (f->pos.r / data()->mlx.winx) * param->delta.r * param->zoom
	+ param->top.r * param->zoom;
	f->z.i = (f->pos.i / data()->mlx.winy) * param->delta.i * param->zoom
	+ param->top.i * param->zoom;
	f->ite = 0;
	while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax)
	{
		f->z.r = FABS(f->z.r);
		f->z.i = FABS(f->z.i);
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->ite++;
	}
	put_pixel(lay, param, f);
}

void		scene_1_draw_bonus2(t_img *lay, t_fract *param, t_fract *f)
{
	f->pos.r = f->i % data()->mlx.winx;
	f->pos.i = f->i / data()->mlx.winx;
	f->z.r = (f->pos.r / data()->mlx.winx) * param->delta.r * param->zoom
	+ param->top.r * param->zoom;
	f->z.i = (f->pos.i / data()->mlx.winy) * param->delta.i * param->zoom
	+ param->top.i * param->zoom;
	f->c.r = (f->pos.r / data()->mlx.winx) * param->delta.r * param->zoom
	+ param->top.r * param->zoom;
	f->c.i = (f->pos.i / data()->mlx.winy) * param->delta.i * param->zoom
	+ param->top.i * param->zoom;
	f->ite = 0;
	f->c = comp_sqr(f->c);
	while (f->z.r * f->z.r + f->z.i * f->z.i < 2 && f->ite < param->itemax)
	{
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->z = comp_add(f->z, f->c);
		f->ite++;
	}
	put_pixel(lay, param, f);
}
