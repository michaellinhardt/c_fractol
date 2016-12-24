/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1_fractol_draw.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:40:00 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/24 14:28:58 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#define FABS(X) X < 0. ? -X : X;

void		fractal_move(t_fract *param)
{
	t_data	*d;

	d = data();
	if (d->mlx.input.left)
	{
		param->top.r += MOVE_VALUE;
		param->bot.r += MOVE_VALUE;
	}
	if (d->mlx.input.right)
	{
		param->top.r -= MOVE_VALUE;
		param->bot.r -= MOVE_VALUE;
	}
	if (d->mlx.input.up)
	{
		param->top.i += MOVE_VALUE;
		param->bot.i += MOVE_VALUE;
	}
	if (d->mlx.input.down)
	{
		param->top.i -= MOVE_VALUE;
		param->bot.i -= MOVE_VALUE;
	}
}

static void	put_pixel(t_img *lay, t_fract *param, t_fract *f)
{
	if ( f->ite >= param->itemin && f->ite <= param->itemax )
		lay->ptr[f->i] = 0x00000000 + (f->ite * 1000);
	else
		lay->ptr[f->i] = 0x00000000 + (f->ite * 10);
}

void		scene_1_draw_mandelbrot(t_img *lay, t_fract *param, t_fract *f)
{
	f->pos.r = f->i % WIN_X;
	f->pos.i = f->i / WIN_X;
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
	f->pos.r = f->i % WIN_X;
	f->pos.i = f->i / WIN_X;
	f->z.r = (f->pos.r / WIN_X) * param->delta.r + param->top.r;
	f->z.i = (f->pos.i / WIN_Y) * param->delta.i + param->top.i;
	f->ite = 0;
	 while( f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax
	&& f->dist.r < 1e10 && f->dist.i < 1e10 )
	{

		f->z = comp_add(comp_sqr(f->z), f->c);
		f->old_z.r = 2.0 * (f->z.r * f->old_z.r - f->z.i * f->old_z.i);
		f->old_z.i = 2.0 * (f->z.i * f->old_z.r - f->z.r * f->old_z.i);
		f->dist.r = f->z.r * f->z.r * f->z.i * f->z.i;
		f->dist.i = f->old_z.r * f->old_z.r * f->old_z.i * f->old_z.i;
		f->ite++;
	}
	put_pixel(lay, param, f);
}

void		scene_1_draw_third(t_img *lay, t_fract *param, t_fract *f)
{
	f->pos.r = f->i % WIN_X;
	f->pos.i = f->i / WIN_X;
	f->c.r = (f->pos.r / WIN_X) * param->delta.r + param->top.r;
	f->c.i = (f->pos.i / WIN_Y) * param->delta.i + param->top.i;
	f->z.r = 0;
	f->z.i = 0;
	f->ite = 0;
	while( f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax )
	{
		f->z.r = FABS(f->z.r);
		f->z.i = FABS(f->z.i);
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->ite++;
	}
	put_pixel(lay, param, f);
}
