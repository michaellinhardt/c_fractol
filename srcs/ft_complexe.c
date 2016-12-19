/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complexe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 06:58:02 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/19 08:34:12 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_comp	comp_sqr(t_comp a)
{
	t_comp		result;

	result.r = a.r * a.r - a.i * a.i;
	result.i = 2 * a.r * a.i;
	return (result);
}

t_comp	comp_add(t_comp a, t_comp b)
{
	t_comp		result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

t_comp	comp_mult(t_comp a, t_comp b)
{
	t_comp		result;

	result.r = a.r * b.r - a.i * b.i;
	result.i = a.i * b.r + a.r * b.i;
	return (result);
}

t_comp	comp_mult_real(t_comp a, double b)
{
	t_comp		result;

	result.r = a.r * b;
	result.i = a.i * b;
	return (result);
}
