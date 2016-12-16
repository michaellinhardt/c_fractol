/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_mlx.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:33:03 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/16 20:31:08 by mlinhard         ###   ########.fr       */
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
 * a faire..
 * t_img contiens les coordoné d'une image xpm (ou autre ?)
 * la zone recouverte par l'image top[2], bot[2]
 * ainsi que ça position pos[2] et son fade
 * cut_mode indique comment découper l'objet dans le cas d'un menu
 * le groupe de variable anim_ précise comment dois etre affiché l'image
 * une acton est executé selon anim_id, lorsque anim_time est dépassé
 * après l'action, anim_time est incrémenté de anim_tempo
 * - ex: si anim_id = FADE_IN, fade sera initialisé automatiquement a transparent
 *  	 à chaque affichage, fade est incrémenté jusqu'a son max
 * switch_list décris l'élément suivant à afficher quand anim_time arrive à maturité
 * il dois etre initialisé depuis un header
 * repeat 0 = nope, -1 = infinie, -2 = infinie reverse, >1 = decompte
 * status 0 = off, status 1 = affiché, status -1 = attendre le premier proc de anim_time
 */

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
	int				bpp;
	int				sl;
	int				end;
	int				i;
	char			name[255];
	int				top[2];
	int				bot[2];
	int				xy[2];
	int				fade;
	enum e_anim		e_anim_id;
	int				anim_time;
	int				anim_tempo;
	int				anim_repeat;
	int				mouse_status;
	int				mouse_btn;
	void 			(*mouse_action)(void);
	int				status;
	struct s_img	*switch_with[SCENE_MAX][SCENE_IMG_MAX];
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
	t_img			layer;
}					t_dmlx;

#endif
