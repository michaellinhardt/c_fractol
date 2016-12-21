/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:17:47 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/21 19:04:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		zoomin(t_dmlx *m, t_fract *param)
{
	param->top.r += ZOOM_VALUE;
	param->top.i += ZOOM_VALUE;
	param->bot.r -= ZOOM_VALUE;
	param->bot.i -= ZOOM_VALUE;
	if (m->input.mo_x < (WIN_X / 2))
	{
		param->top.r += ZOOM_VALUE / 2;
	}
	else if (m->input.mo_x > (WIN_X / 2))
	{
		param->top.r -= ZOOM_VALUE / 2;
	}
	if (m->input.mo_y < (WIN_Y / 2))
	{
		param->top.i += ZOOM_VALUE / 2;
	}
	else if (m->input.mo_y > (WIN_Y / 2))
	{
		param->top.i -= ZOOM_VALUE / 2;
	}
	fractal_param(2);
	(void)m;
	(void)param;
}

void		zoomout(t_dmlx *m, t_fract *param)
{
	param->top.r -= ZOOM_VALUE;
	param->top.i -= ZOOM_VALUE;
	param->bot.r += ZOOM_VALUE;
	param->bot.i += ZOOM_VALUE;
	fractal_param(2);
	(void)m;
	(void)param;
}
