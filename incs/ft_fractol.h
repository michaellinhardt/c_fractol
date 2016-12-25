/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:32:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 21:08:50 by mlinhard         ###   ########.fr       */
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
# include <pthread.h>
# include "libft.h"
# include "mlx.h"
# include "ft_conf.h"
# include "ft_struct_fractol.h"
# include "ft_struct_mlx.h"
# include "ft_struct_data.h"
# include "ft_mlx.h"
# include "ft_mlx_scene_conf.h"

t_data				*data(void);
t_fract				*fractal(int init, int thread);
void				catch_options(t_data *d, int argc, char **argv, int i);
t_fract				*fractal_param(int init);
void				fractal_move(t_fract *param);

void				zoomin(t_dmlx *m, t_fract *param);
void				zoomout(t_dmlx *m, t_fract *param);

t_comp				comp_sqr(t_comp a);
t_comp				comp_add(t_comp a, t_comp b);
t_comp				comp_mult(t_comp a, t_comp b);
t_comp				comp_mult_real(t_comp a, double b);

int					l1(char ico, char *name, char *info);
int					l2(char ico, char *name, char *info, int val1);

int					exit1(int err, t_data *d, char *msg);
int					exit2(int err, t_data *d, char *del, char *msg);

void				free_data(t_data *d);
void				ft_display_help(void);

#endif
