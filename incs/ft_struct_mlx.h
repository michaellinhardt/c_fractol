/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_mlx.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:33:03 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 21:09:41 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_MLX_H
# define FT_STRUCT_MLX_H

enum	e_scene {
	INTRO,
	FRACTOL
};

enum	e_anim {
	STATIC,
	FADE_IN,
	FADE_OUT,
	BLING_BLING,
	SWITCH_WITH,
	MOVE,
	DISABLE
};

typedef struct		s_img
{
	void			*img;
	char			*str;
	int				*ptr;
	int				bpp;
	int				sl;
	int				end;
	int				i;
	char			name[255];
	int				pos[2];
	int				top[2];
	int				bot[2];
	int				xy[2];
	int				fade;
	enum e_anim		anim_id;
	int				anim_time;
	int				anim_tempo;
	int				anim_repeat;
	int				mouse_status;
	int				mouse_btn;
	void			(*mouse_action)(void);
	int				status;
	struct s_img	*switch_with[SCENE_MAX][SCENE_IMG_MAX];
	int				width;
	int				heigh;
}					t_img;

typedef struct		s_input
{
	char			mode;
	char			mleft;
	char			mright;
	char			left;
	char			right;
	char			up;
	char			down;
	char			shift;
	int				wheelup;
	int				wheeldown;
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
	int				winx;
	int				winy;
}					t_dmlx;

#endif
