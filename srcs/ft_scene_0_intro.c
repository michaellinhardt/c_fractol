/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_0_intro.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 03:55:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/17 20:40:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		scene_0_intro(t_data *d, t_dmlx *m)
{
	if (m->scene_img[0][0].fade == 255
		&& m->scene_img[0][0].anim_id == FADE_OUT)
			m->scene++;
	scene_img_push(d, m, -1, (t_img *)NULL);
	itow(layer(0, 0)->img, 0, 0, "push layer 0 to window");
	itow(layer(1, 0)->img, 0, 0, "push layer 1 to window");
	(void)d;
	(void)m;
}
