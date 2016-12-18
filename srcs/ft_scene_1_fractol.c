/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 03:55:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/18 01:17:33 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	*calc_pixel(void *i)
{
	t_dmlx	*m;
	t_img	*lay;
	int		end;
	int		portion;

	m = &data()->mlx;
	lay = layer(2, 0);
	portion = (WIN_X * WIN_Y) / TOTAL_THREADS;
	lay->i = portion * (*((int *)i))- 1;
	end = ((*((int *)i)) == (TOTAL_THREADS - 1)) ? WIN_X * WIN_Y : lay->i + portion;
	while ( ++lay->i < end )
	{
		if(((*((int *)i)) & 1) == 0)
			lay->ptr[lay->i] = 0x0091fb30;
		else
			lay->ptr[lay->i] = 0x00b33e66;
	}
	return (NULL);
}

void		scene_1_fractol(t_data *d, t_dmlx *m, int i)
{
	pthread_t threads[TOTAL_THREADS];

	layer(2, 1);
	while( ++i < TOTAL_THREADS )
	{
		if (pthread_create(&threads[i], NULL, calc_pixel, &i))
			exit1(1, d, "cant create threads");
		pthread_join(threads[i], (void **)NULL);
	}
	i = -1;
	while( ++i < TOTAL_THREADS )
		pthread_join(threads[i], (void **)NULL);
	itow(layer(0, 0)->img, 0, 0, "push layer 0 to window");
	scene_img_push(d, m, -1, (t_img *)NULL);
	itow(layer(1, 0)->img, 0, 0, "push layer 1 to window");
	itow(layer(2, 0)->img, 0, 0, "push layer 1 to window");

	(void)d;
	(void)m;
}
