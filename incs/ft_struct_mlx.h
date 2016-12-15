/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_mlx.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:33:03 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/15 04:05:39 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_MLX_H
# define FT_STRUCT_MLX_H

enum	e_scene {
	INTRO_LOAD,
	INTRO_MENU,
	INTRO_OUT,
	FRACTOL_INIT,
	FRACTOL
};


/*
 * t_img contiens les coordoné d'une image xpm (ou autre ?)
 * la zone recouverte par l'image top[2], bot[2]
 * ainsi que ça position pos[2] et son fade
 * cut_mode indique comment découper l'objet dans le cas d'un menu
 */
typedef struct		s_img
{
	void			*img;
	char			*str;
	int				bpp;
	int				sl;
	int				end;
	int				i;
	char			name[255];
	int				top[2];
	int				bot[2];
	int				pos[2];
	int				fade;
	int				cut_mode;
	int				width;
	int				heigh;
}					t_img;

typedef struct		s_input
{
	char			mleft;
	char			mright;
	char			left;
	char			right;
	char			up;
	char			down;
	char			shift;
	int				mo_x;
	int				mo_y;
	int				mr_x;
	int				mr_y;
}					t_input;

typedef struct		s_dmlx
{
	void			*mlx;
	void			*win;
	t_input			input;
	char			sound;
	char			loop;
	char			loopstop;
	enum e_scene	scene;
	char			img_isload[SCENE_MAX];
	t_img			scene_img[SCENE_MAX][SCENE_IMG_MAX];
}					t_dmlx;

#endif
