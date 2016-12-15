/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_img_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:11:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/15 06:19:20 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"


void		scene_img_init_0_intro(t_data *d, t_dmlx *m)
{
	ft_memcpy(m->scene_img[0][0].name, "0_bg_intro.xpm\0", 15);
	m->scene_img[0][0].bot[0] = WIN_X;
	m->scene_img[0][0].bot[1] = WIN_Y;
	m->scene_img[0][0].fade = 0;
	m->scene_img[0][0].width = m->scene_img[0][0].bot[0] - m->scene_img[0][0].top[0];
	m->scene_img[0][0].heigh = m->scene_img[0][0].bot[1] - m->scene_img[0][0].top[1];
	l1(1, "IMG_INIT", m->scene_img[0][0].name);
	(void)d;
	(void)m;
}

void		scene_img_init(t_data *d, t_dmlx *m)
{
	l1(1, "IMG_INIT", "initialising t_img data");
	if (m->scene == INTRO_LOAD)
		scene_img_init_0_intro(d, m);
	(void)d;
	(void)m;
}
