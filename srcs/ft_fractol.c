/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:33:11 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 16:53:51 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	d->mlx.winx = WIN_X;
	d->mlx.winy = WIN_Y;
	catch_options(d, argc, argv, 0);
	if (d->args.console)
	{
		ascii(ASC_LOGO);
		ascii(ASC_INIT);
		ascii_init();
		ascii(ASC_LOG);
	}
	mlx_start(d, &d->mlx);
	return (0);
}
