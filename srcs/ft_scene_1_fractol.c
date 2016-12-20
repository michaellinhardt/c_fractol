/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 03:55:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/20 04:03:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_fract		*fractal_param(int init)
{
	static t_fract	param;

	if (init == 1)
	{
		param.itemax = 400;
		param.itemin = 50;
		if (data()->args.fractal == JULIA)
		{
			param.top.r = -1;
			param.top.i = -1.2;
			param.bot.r = 1;
			param.bot.i = 1.2;
		}
		else if (data()->args.fractal == MANDELBROT)
		{
			param.top.r = -2.1;
			param.top.i = -1.2;
			param.bot.r = 0.6;
			param.bot.i = 1.2;
		}
		else if (data()->args.fractal == THIRD)
		{
			param.top.r = -1;
			param.top.i = -1.2;
			param.bot.r = 1;
			param.bot.i = 1.2;
		}
		param.delta.r = param.bot.r - param.top.r;
		param.delta.i = param.bot.i - param.top.i;

	}
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
		scene_1_draw_julia(lay, param, f);
	else if (d->args.fractal == MANDELBROT)
		scene_1_draw_mandelbrot(lay, param, f);
	else if (d->args.fractal == THIRD)
		scene_1_draw_third(lay, param, f);
}

static void	*calc_pixel(void *i)
{
	t_dmlx		*m;
	t_img		*lay;
	int			portion;
	t_fract		*f;
	t_fract		*param;

	m = &data()->mlx;
	lay = layer(2, 0);
	f = fractal(0, *((int *)i));
	param = fractal_param(0);
	portion = (WIN_X * WIN_Y) / TOTAL_THREADS;
	f->i = portion * (*((int *)i))- 1;
	param->i = ((*((int *)i)) == (TOTAL_THREADS - 1)) ? WIN_X * WIN_Y : f->i + portion;
	while ( ++f->i < param->i )
	{
		f->posi = f->i;
		f->pos.r = f->i % WIN_X;
		f->pos.i = f->i / WIN_X;
		// printf("%d -> %f,%f -> %f,%f \n", f->posi, f->pos.r, f->pos.i, f->c.r, f->c.i);
		wich_fractol(lay, f);
	}
	return (NULL);
}

void		scene_1_fractol(t_data *d, t_dmlx *m, int i)
{
	pthread_t threads[TOTAL_THREADS];

	layer(2, 1);
	fractal_param(1);
	while( ++i < TOTAL_THREADS )
	{
		fractal(1, i);
		if (pthread_create(&threads[i], NULL, calc_pixel, &i))
			exit1(1, d, "cant create threads");
		pthread_join(threads[i], (void **)NULL);
	}
	i = -1;
	while( ++i < TOTAL_THREADS )
		pthread_join(threads[i], (void **)NULL);
	// itow(layer(0, 0)->img, 0, 0, "push layer 0 to window");
	// scene_img_push(d, m, -1, (t_img *)NULL);
	// itow(layer(1, 0)->img, 0, 0, "push layer 1 to window");
	itow(layer(2, 0)->img, 0, 0, "push layer 1 to window");
	loop(0);
	(void)d;
	(void)m;
}
