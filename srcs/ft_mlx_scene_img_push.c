/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_img_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:11:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/16 16:38:23 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		scene_img_push(t_data *d, t_dmlx *m, int i, t_img *img)
{
	img = layer(1);
	while ( m->scene_img[m->scene][++i].img )
		layer_add(img, &m->scene_img[m->scene][i]);
	(void)d;
}
