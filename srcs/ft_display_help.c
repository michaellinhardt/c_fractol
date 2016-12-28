/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 20:55:35 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/28 06:47:46 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_display_help(void)
{
	ft_putendl("  Syntax:");
	ft_putendl("  \t./fractal <options> <fractal name>\n");
	ft_putendl("  Options:");
	ft_putendl("  \t-l\tdisplay log system");
	ft_putendl("  \t-s\tenable sound");
	ft_putendl("  \t-i\tskip intro");
	ft_putendl("  \t-x<int>\tchange x window size");
	ft_putendl("  \t-y<int>\tchange y window size\n");
	ft_putendl("  Fractal list:");
	ft_putendl("  \tJulia");
	ft_putendl("  \tMandelbrot");
	ft_putendl("  \tThird");
	ft_putendl("  \tBonus1");
	ft_putendl("  \tBonus2");
	exit(0);
}
