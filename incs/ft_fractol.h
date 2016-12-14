/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:32:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/14 11:39:56 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <fcntl.h>
# include <dirent.h>
# include <limits.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "ft_conf.h"
# include "ft_struct_mlx.h"
# include "ft_struct_data.h"
# include "ft_mlx.h"

t_data		*data(void);

int			l1(char ico, char *name, char *info);
int			l2(char ico, char *name, char *info, int val1);

int			exit1(int err, t_data *d, char *msg);
int			exit2(int err, t_data *d, char *del, char *msg);

void		free_data(t_data *d);

void		ft_display_help(void);

#endif
