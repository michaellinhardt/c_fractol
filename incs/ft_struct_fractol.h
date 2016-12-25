/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_fractol.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:32:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 21:08:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_FRACTOL_H
# define FT_STRUCT_FRACTOL_H

enum	e_fractal {
	NONE,
	JULIA,
	THIRD,
	MANDELBROT
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
	t_comp			bot;
	t_comp			delta;
	t_comp			dist;
	t_comp			old_z;
	int				itemax;
	int				itemin;
	int				ite;
	int				i;
	t_comp			z;
	t_comp			c;
	t_comp			tmp;
}					t_fract;

#endif
