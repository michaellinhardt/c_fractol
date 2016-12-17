/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:33:02 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/17 03:48:21 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_DATA_H
# define FT_STRUCT_DATA_H

typedef struct			s_data
{
	struct s_dmlx		mlx;
	char				folder[255];
	char				console;
	char				sound;
	Mix_Music			*son;
}						t_data;

#endif
