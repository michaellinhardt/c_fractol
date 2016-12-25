/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 20:57:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 20:57:16 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int		mouseo_hook(int x, int y, t_data *d)
{
	if (data()->mlx.scene == INTRO)
		return (0);
	d->mlx.input.mo_x = x;
	d->mlx.input.mo_y = y;
	loopstop(5);
	return (0);
}

int		keyr_hook(int key, t_data *d)
{
	if (key == 53)
		exit1(0, d, "by pressing echap");
	else if (d->mlx.scene > INTRO)
	{
		(key == 123 && loopstop(5)) ? d->mlx.input.left = 0 : 0;
		(key == 124 && loopstop(5)) ? d->mlx.input.right = 0 : 0;
		(key == 125 && loopstop(5)) ? d->mlx.input.down = 0 : 0;
		(key == 126 && loopstop(5)) ? d->mlx.input.up = 0 : 0;
		if (key == 116 && loopstop(5))
			d->mlx.input.wheelup = 0;
		if (key == 121 && loopstop(5))
			d->mlx.input.wheeldown = 0;
	}
	return (0);
}

int		keyp_hook(int key, t_data *d)
{
	(key == 123 && loopstop(5)) ? d->mlx.input.left = 1 : 0;
	(key == 124 && loopstop(5)) ? d->mlx.input.right = 1 : 0;
	(key == 125 && loopstop(5)) ? d->mlx.input.down = 1 : 0;
	(key == 126 && loopstop(5)) ? d->mlx.input.up = 1 : 0;
	if (key == 116 && loopstop(5))
		d->mlx.input.wheelup = 1;
	if (key == 121 && loopstop(5))
		d->mlx.input.wheeldown = 1;
	return (0);
}

int		mousep_hook(int btn, int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	(btn == 1) ? d->mlx.input.mleft = 1 : 0;
	(btn == 2) ? d->mlx.input.mright = 1 : 0;
	if (d->mlx.scene > INTRO)
	{
		if (btn == 4)
			zoomin(&data()->mlx, fractal_param(0));
		if (btn == 5)
			zoomout(&data()->mlx, fractal_param(0));
		loopstop(5);
	}
	return (0);
}

int		mouser_hook(int btn, int x, int y, t_data *d)
{
	(btn == 1) ? d->mlx.input.mleft = 0 : 0;
	(btn == 2) ? d->mlx.input.mright = 0 : 0;
	d->mlx.input.mr_x = x;
	d->mlx.input.mr_y = y;
	mouse_check_img(&data()->mlx, btn, (t_img *)NULL, -1);
	return (0);
}
