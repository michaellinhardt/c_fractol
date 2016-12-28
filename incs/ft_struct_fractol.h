/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_fractol.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:32:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/28 02:31:02 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_FRACTOL_H
# define FT_STRUCT_FRACTOL_H

enum	e_fractal {
	NONE,
	THIRD,
	MANDELBROT,
	JULIA,
	BONUS1,
	BONUS2
};

typedef struct		s_comp
{
	double			r;
	double			i;
}					t_comp;

typedef struct		s_fract
{
	int				posi;
	t_comp			pos;
	t_comp			top;
	t_comp			mousediff;
	t_comp			bot;
	t_comp			delta;
	t_comp			dist;
	t_comp			old_z;
	int				itemax;
	int				itemin;
	int				ite;
	int				i;
	double			zoom;
	t_comp			z;
	t_comp			c;
	t_comp			tmp;
}					t_fract;

#endif
