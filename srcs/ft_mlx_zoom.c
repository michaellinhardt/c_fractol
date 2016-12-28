/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:17:47 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/28 02:47:08 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		zoomin(t_dmlx *m, t_fract *param)
{
	param->zoom -= ZOOM_VALUE;
	(void)m;
}

void		zoomout(t_dmlx *m, t_fract *param)
{
	param->zoom += ZOOM_VALUE;
	(void)m;
}
