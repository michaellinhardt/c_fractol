/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_s0_mouse_action.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 03:36:36 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 20:58:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		intro_start_fade_out(void)
{
	t_img		*img;

	img = &data()->mlx.scene_img[0][0];
	img->anim_id = FADE_OUT;
}
