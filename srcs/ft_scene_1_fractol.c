/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_1_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 03:55:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/18 01:07:23 by mlinhard         ###   ########.fr       */
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
	portion = (WIN_X * WIN_Y) / 8;
	lay->i = portion * (*((int *)i))- 1;
	end = ((*((int *)i)) == 7) ? WIN_X * WIN_Y : lay->i + portion;
	while ( ++lay->i < end )
	{
		if ((*((int *)i)) == 0 || (*((int *)i)) == 3 || (*((int *)i)) == 6)
			lay->ptr[lay->i] = 0x0091fb30;
		else if ((*((int *)i)) == 1 || (*((int *)i)) == 4 || (*((int *)i)) == 7)
			lay->ptr[lay->i] = 0x00b33e66;
		else if ((*((int *)i)) == 2 || (*((int *)i)) == 5)
			lay->ptr[lay->i] = 0x00c167d4;
	}
	return (NULL);
}

void		scene_1_fractol(t_data *d, t_dmlx *m, int i)
{
	pthread_t threads[8];

	layer(2, 1);
	while( ++i < 8 )
	{
		if (pthread_create(&threads[i], NULL, calc_pixel, &i))
			exit1(1, d, "cant create threads");
		pthread_join(threads[i], (void **)NULL);
	}
	i = -1;
	while( ++i < 8 )
		pthread_join(threads[i], (void **)NULL);
	itow(layer(0, 0)->img, 0, 0, "push layer 0 to window");
	scene_img_push(d, m, -1, (t_img *)NULL);
	itow(layer(1, 0)->img, 0, 0, "push layer 1 to window");
	itow(layer(2, 0)->img, 0, 0, "push layer 1 to window");

	(void)d;
	(void)m;
}
