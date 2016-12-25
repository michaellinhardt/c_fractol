/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_img_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:11:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 21:00:20 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static char		*add_message(char *name, char *msg)
{
	static char		message[1024];
	char			*pmessage;

	pmessage = message;
	while (*name)
		*pmessage++ = *name++;
	while (*msg)
		*pmessage++ = *msg++;
	return (message);
}

void			scene_img_init_scene(t_dmlx *m, t_img *img, int i)
{
	while (m->scene_img[m->scene][++i].img)
	{
		img = &m->scene_img[0][i];
		if (img->anim_id == FADE_IN)
		{
			l1(1, "IMG_INIT"
			, add_message(m->scene_img[0][i].name, ": init fade_in effect"));
			img->fade = 255;
		}
	}
}

static void		init_lay_color(t_img *img)
{
	t_dmlx *m;

	m = &data()->mlx;
	img->i = -1;
	while (++img->i < m->winx * m->winy)
		img->ptr[img->i] = 0x001E1E1E;
}

void			scene_img_init_0_intro(t_data *d, t_dmlx *m, t_img *img)
{
	img = &m->scene_img[0][0];
	if (m->winx <= img->width + 10 || m->winy <= img->heigh + 10)
		exit1(1, d
		, "window size_x must be over 560, window size_y must be over 170");
	ft_memcpy(img->name, "0_intro_logo.xpm\0", 15);
	img->pos[0] = (m->winx / 2) - (img->width / 2) + 5;
	img->pos[1] = (m->winy / 2) - (img->heigh / 2) - 5;
	img->bot[0] = m->winx;
	img->bot[1] = m->winy;
	img->mouse_btn = S0I0_MOUSE_BTN;
	img->mouse_action = S0I0_MOUSE_ACTION;
	img->anim_id = S0I0_ANIM_ID;
	l1(1, "IMG_INIT", m->scene_img[0][0].name);
	layer(2, 2);
	init_lay_color(layer(0, 0));
	(void)d;
}

void			scene_img_init(t_data *d, t_dmlx *m)
{
	l1(1, "IMG_INIT", "initialising scene img");
	if (m->scene == INTRO)
		scene_img_init_0_intro(d, m, (t_img *)NULL);
	scene_img_init_scene(m, (t_img *)NULL, -1);
	(void)d;
	(void)m;
}
