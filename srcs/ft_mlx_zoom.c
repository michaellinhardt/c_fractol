/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:17:47 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 16:51:11 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		zoomin(t_dmlx *m, t_fract *param)
{
	param->top.r += ZOOM_VALUE;
	param->top.i += ZOOM_VALUE;
	param->bot.r -= ZOOM_VALUE;
	param->bot.i -= ZOOM_VALUE;
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
