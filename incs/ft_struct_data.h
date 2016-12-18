/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:33:02 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/18 22:49:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_DATA_H
# define FT_STRUCT_DATA_H

typedef struct			s_args
{
	char				fractal[ARGS_MAX_SIZE];
	char				got_fractal;
	char				console;
	char				sound;
}						t_args;

typedef struct			s_data
{
	struct s_dmlx		mlx;
	struct s_args		args;
	char				folder[255];
	Mix_Music			*son;
}						t_data;

#endif
