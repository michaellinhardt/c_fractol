/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 03:55:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 21:06:16 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_fract		*fractal_param(int init)
{
	static t_fract	param;

	if (init == 0)
		return (&param);
	if (init == 1 && (param.itemax = ITE_MAX || 1))
	{
		if ((param.itemin = ITE_MIN || 1) && data()->args.fractal == JULIA)
		{
			param.top.r = -1;
			param.top.i = -1.2;
			param.bot.r = 1;
			param.bot.i = 1.2;
		}
		else if (data()->args.fractal == MANDELBROT
		|| data()->args.fractal == THIRD)
		{
			param.top.r = -2.1;
			param.top.i = -1.2;
			param.bot.r = 0.6;
			param.bot.i = 1.2;
		}
	}
	param.delta.r = param.bot.r - param.top.r;
	param.delta.i = param.bot.i - param.top.i;
	return (&param);
}

t_fract		*fractal(int init, int thread)
{
	static t_fract	f[TOTAL_THREADS];

	if (init == 1)
		ft_bzero(&f[thread], sizeof(t_fract));
	return (&f[thread]);
}

static void	wich_fractol(t_img *lay, t_fract *f)
{
	t_data		*d;
	t_fract		*param;

	d = data();
	param = fractal_param(0);
	if (d->args.fractal == JULIA)
		while (++f->i < param->i)
			scene_1_draw_julia(lay, param, f);
	else if (d->args.fractal == MANDELBROT)
		while (++f->i < param->i)
			scene_1_draw_mandelbrot(lay, param, f);
	else if (d->args.fractal == THIRD)
		while (++f->i < param->i)
			scene_1_draw_third(lay, param, f);
}

static void	*calc_pixel(void *i)
{
	int			portion;
	t_fract		*f;
	t_fract		*param;

	f = fractal(0, *((int *)i));
	param = fractal_param(0);
	fractal_move(param);
	if (data()->mlx.input.wheelup)
		zoomin(&data()->mlx, fractal_param(0));
	if (data()->mlx.input.wheeldown)
		zoomout(&data()->mlx, fractal_param(0));
	if (data()->args.fractal == JULIA)
	{
		f->c.r = ((double)data()->mlx.input.mo_x / (double)data()->mlx.winx)
		* param->delta.r + param->top.r;
		f->c.i = ((double)data()->mlx.input.mo_y / (double)data()->mlx.winy)
		* param->delta.i + param->top.i;
	}
	portion = (data()->mlx.winx * data()->mlx.winy) / TOTAL_THREADS;
	f->i = portion * (*((int *)i)) - 1;
	param->i = ((*((int *)i)) == (TOTAL_THREADS - 1)) ? data()->mlx.winx
	* data()->mlx.winy : f->i + portion;
	wich_fractol(layer(2, 0), f);
	return (NULL);
}

void		scene_1_fractol(t_data *d, t_dmlx *m, int i)
{
	pthread_t threads[TOTAL_THREADS];

	layer(2, 1);
	while (++i < TOTAL_THREADS)
	{
		fractal(1, i);
		if (pthread_create(&threads[i], NULL, calc_pixel, &i))
			exit1(1, d, "cant create threads");
		pthread_join(threads[i], (void **)NULL);
	}
	i = -1;
	while (++i < TOTAL_THREADS)
		pthread_join(threads[i], (void **)NULL);
	itow(layer(2, 0)->img, 0, 0, "push layer 1 to window");
	loop(0);
	(void)d;
	(void)m;
}
