/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_img_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 04:11:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/16 20:27:01 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static char	*add_message(char *name, char *msg)
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

void		scene_img_init_scene(t_dmlx *m, t_img *img, int i)
{
	while ( m->scene_img[m->scene][++i].img )
	{
		img = &m->scene_img[0][0];
		img->width = img->bot[0] - img->top[0];
		img->heigh = img->bot[1] - img->top[1];
		l1(1, "IMG_INIT"
		, add_message(m->scene_img[0][0].name, ": calcul area width & heigh"));
	}
}

void		scene_img_init_0_intro(t_data *d, t_dmlx *m, t_img *img)
{
	img = &m->scene_img[0][0];
	ft_memcpy(img->name, "0_bg_intro.xpm\0", 15);
	img->bot[0] = WIN_X;
	img->bot[1] = WIN_Y;
	img->fade = 0;

	l1(1, "IMG_INIT", m->scene_img[0][0].name);
	(void)d;
}

void		scene_img_init(t_data *d, t_dmlx *m)
{
	l1(1, "IMG_INIT", "initialising t_img data");
	if (m->scene == INTRO_LOAD)
		scene_img_init_0_intro(d, m, (t_img *)NULL);
	scene_img_init_scene(m, (t_img *)NULL, -1);
	(void)d;
	(void)m;
}
