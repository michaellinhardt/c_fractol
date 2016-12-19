/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1_fractol_draw.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:40:00 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/19 09:02:33 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		scene_1_draw_mandelbrot(t_img *img, t_fract *param, t_fract *f)
{
	img->ptr[f->posi] = 0x00b33e66;
	printf("%d -> %d,%d\n", f->posi,)
	return ;
	while( f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->ite < param->itemax )
	{
		f->z = comp_add(comp_sqr(f->z), f->c);
		f->ite++;
	}

	if ( f->ite == param->itemax )
		img->ptr[f->posi] = 0x0091fb30;
	else
		img->ptr[f->posi] = 0x00b33e66;
}

void		scene_1_draw_julia(t_img *img, t_fract *param, t_fract *f)
{

// 	f->r1 = -2.1;
// 	f->r2 = 0.6;

// 	f->i1 = -1.2;
// 	f->i2 = 1.2;
//
// 	0,0 = -2.1,-1.2
// 	500,500 = 0.6,1.2
// 	0.6 --2.1 dx
// 	1.2--1.2 dy
// 	dx * px + -2.1
// 	dy * py + -1.2
//

//
// 	f->c_r = f->x / f->zoom + f->x1;
// 	f->c_i = f->y / f->zoom + f->y1;
// 	f->z_r = 0;
// 	f->z_i = 0;
// 	f->i = 0;
//
// 	while( f->z_r * f->z_r + f->z_i * f->z_i < 4 && f->i < f->itemax )
// 	{
// 		z = comp_add(comp_sqr(z), c);
// 		f->tmp = f->z_r;
// 		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
// 		f->z_i = 2 * f->tmp * f->z_i + f->c_i;
// 		f->i++;
// 	}
//
// 	if ( f->i == f->itemax )
// 		img->ptr[f->posi] = 0x0091fb30;
// 	else
// 		img->ptr[f->posi] = 0x00b33e66;

	(void)param;
	(void)img;
	(void)f;
}
