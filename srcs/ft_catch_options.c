/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 22:17:45 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/18 23:08:08 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void		catch_this_one(t_data *d, char *arg)
{
	if (arg[0] != '-')
	{
		if (ft_strlen(arg) >= ARGS_MAX_SIZE)
			exit1(1, d, "Argument excced ARGS_MAX_SIZE in ft_conf.h");
		else if (++d->args.got_fractal == 2)
			exit1(1, d, "Only one fractal can be passed as argument");
		ft_strcpy(d->args.fractal, arg);

	}
	else if (ft_strcmp(arg, "-s") == 0)
		d->args.sound = 1;
	else if (ft_strcmp(arg, "-l") == 0)
		d->args.console = 1;
	else if (ft_strcmp(arg, "-i") == 0)
		d->mlx.scene = FRACTOL;
	else if (ft_strcmp(arg, "-h") == 0)
	{
		d->args.console = 0;
		ft_display_help();
		exit(0);
	}
}

void		catch_options(t_data *d, int argc, char **argv, int i)
{
	while ( ++i < argc )
		catch_this_one(d, argv[i]);
}
