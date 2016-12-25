/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook_click.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 20:56:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 20:57:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	mouse_check_img(t_dmlx *m, int btn, t_img *img, int i)
{
	while (m->scene_img[m->scene][++i].img)
	{
		img = &m->scene_img[0][i];
		if (m->input.mode == 0
		&& (img->mouse_btn == 3 || (img->mouse_btn == btn))
		&& (m->input.mr_x >= img->top[0] && m->input.mr_x <= img->bot[0])
		&& (m->input.mr_y >= img->top[1] && m->input.mr_y <= img->bot[1]))
			img->mouse_action();
	}
}
