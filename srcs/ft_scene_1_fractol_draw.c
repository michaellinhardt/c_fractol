/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1_fractol_draw.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:40:00 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/20 04:12:25 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	put_pixel(t_img *lay, t_fract *param, t_fract *f)
{
	if ( f->ite >= param->itemin && f->ite <= param->itemax )
		lay->ptr[f->posi] = 0x00000000 + (f->ite * 1000);
	else
		lay->ptr[f->posi] = 0x00000000 + (f->ite * 10);
}

void		scene_1_draw_mandelbrot(t_img *lay, t_fract *param, t_fract *f)
{
	f->c.r = (f->pos.r / WIN_X) * param->delta.r + param->top.r;
	f->c.i = (f->pos.i / WIN_Y) * param->delta.i + param->top.i;
	f->z.r = 0;
	f->z.i = 0;
	f->ite = 0;
	while( f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax )
	{
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->ite++;
	}
	put_pixel(lay, param, f);
}

void		scene_1_draw_julia(t_img *lay, t_fract *param, t_fract *f)
{
	f->c.r = 0.285;
	f->c.i = 0.01;
	f->z.r = (f->pos.r / WIN_X) * param->delta.r + param->top.r;
	f->z.i = (f->pos.i / WIN_Y) * param->delta.i + param->top.i;
	f->ite = 0;
	while( f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax )
	{
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->ite++;
	}
	put_pixel(lay, param, f);
}

void		scene_1_draw_third(t_img *lay, t_fract *param, t_fract *f)
{
	f->c.r = 0.285;
	f->c.i = 0.01;
	f->z.r = (f->pos.r / WIN_X) * param->delta.r + param->top.r;
	f->z.i = (f->pos.i / WIN_Y) * param->delta.i + param->top.i;
	f->ite = 0;
	while( f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax )
	{
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->ite++;
	}
	put_pixel(lay, param, f);
}