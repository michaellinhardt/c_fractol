/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:32:48 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/14 10:32:49 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_data	*data(void)
{
	static t_data	d;
	static int		init = 0;

	if (!init && ++init)
		ft_bzero(&d, sizeof(t_data));
	return (&d);
}
