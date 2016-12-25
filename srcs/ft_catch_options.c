/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 22:17:45 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 20:53:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void		window_size(t_dmlx *m, char *arg, int i)
{
	char	val[11];
	int		*ptr;
	int		xy;

	ptr = (arg[1] == 'x') ? &m->winx : &m->winy;
	if (arg[1] == 'x')
		xy = 1;
	else
		xy = 2;
	arg++;
	while (++arg && ft_isdigit(*arg) && ++i && i < 11)
		val[i] = *arg;
	*ptr = ft_atoi(arg);
	if (xy == 1 && *ptr > WIN_X_MAX && !(data()->args.console = 0))
		exit1(1, data(), "window size_x must be under 1920");
	else if (xy == 2 && *ptr > WIN_Y_MAX && !(data()->args.console = 0))
		exit1(1, data(), "window size_y must be under 1200");
}

static void		catch_this_one(t_data *d, char *arg)
{
	if (arg[0] != '-')
	{
		if (++d->args.got_fractal == 2 && !(d->args.console = 0))
			exit1(1, d, "Only one fractal can be passed as argument");
		else if (ft_strcmp(ft_strtolower(arg), "julia") == 0)
			d->args.fractal = JULIA;
		else if (ft_strcmp(ft_strtolower(arg), "mandelbrot") == 0)
			d->args.fractal = MANDELBROT;
		else if (ft_strcmp(ft_strtolower(arg), "third") == 0)
			d->args.fractal = THIRD;
	}
	else if (ft_strcmp(arg, "-s") == 0)
		d->args.sound = 1;
	else if (ft_strcmp(arg, "-l") == 0)
		d->args.console = 1;
	else if (ft_strcmp(arg, "-i") == 0)
		d->mlx.scene = FRACTOL;
	else if (arg[0] == '-' && (arg[1] == 'x' || arg[1] == 'y'))
		window_size(&d->mlx, arg, -1);
	else if (ft_strcmp(arg, "-h") == 0)
	{
		d->args.console = 0;
		ft_display_help();
		exit(0);
	}
}

void			catch_options(t_data *d, int argc, char **argv, int i)
{
	while (++i < argc)
		catch_this_one(d, argv[i]);
	if (d->args.fractal == NONE)
		ft_display_help();
	fractal_param(1);
}
