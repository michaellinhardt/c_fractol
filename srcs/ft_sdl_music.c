/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_music.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 20:59:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 20:59:31 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			ft_init_music(t_data *d, int off)
{
	if (off)
	{
		Mix_FreeMusic(d->son);
		d->son = NULL;
	}
	else
	{
		d->son = NULL;
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
			ft_printf("%s", Mix_GetError());
	}
	return (1);
}

void		ft_music_start(t_data *d, int off)
{
	if (!d->args.sound)
		return ;
	else if (!off && ft_init_music(d, 0))
		d->son = Mix_LoadMUS("./music/ff7_prelude.mp3");
	else if (off == 1 && ft_init_music(d, 1))
		d->son = Mix_LoadMUS("./music/ff7_red13.mp3");
	Mix_PlayMusic(d->son, -1);
}
