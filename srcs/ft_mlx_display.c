#include "ft_corewar.h"

void	reset_img(t_dmlx *m, t_img *img)
{
	int		*ptr;

	if (m->scene == END)
		return ;
	img->i = -1;
	ptr = (int *)img->str;
	while (++img->i < WIN_X * WIN_Y)
		ptr[img->i] = 0xFF000000;
}

void	bloc_fadeout(t_img *i)
{
	int		fade;

	if (DONT_CLEAN_PROC)
		return ;
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		if ((unsigned char)i->str[i->i + 3] == fade)
			continue ;
		fade = (unsigned char)i->str[i->i + 3] + (unsigned char)BLOC_FADE;
		if (fade > 255)
			i->str[i->i + 3] = (unsigned char)255;
		else
			i->str[i->i + 3] = (unsigned char)fade;
	}
}

int		display(t_dmlx *m, t_dvm *v)
{
	l2(100, "DISPLAYING", "build and print screen..", v->cycle);
	itow(m->scene_img[VM][0].img, 0, 0, "vm background");
	reset_img(m, &m->scene_img[VM][11]);
	display_effect(m, v, effect_data(), -1);
	itow(m->scene_img[VM][11].img, 0, 0, "effect layer");
	display_cycle(m, v);
	display_ctodie_bar(m, v, 0.0, 0);
	reset_img(m, &m->scene_img[VM][10]);
	bloc_fadeout(&m->scene_img[VM][26]);
	display_processus(m, v->proc, &m->scene_img[VM][26]);
	display_processus_count(m, v);
	if (v->nbr_proc)
		display_bar_proc(m, v, &m->scene_img[VM][10], 0);
	if (v->nbr_proc_dead)
		display_bar_proc_dead(m, v, &m->scene_img[VM][10], 0);
	if (v->total_live)
		display_bar_proc_live(m, v, &m->scene_img[VM][10], 0);
	if (v->nbr_live_current)
		display_bar_proc_live_current(m, v, &m->scene_img[VM][10], 0);
	itow(m->scene_img[VM][10].img, 0, 0, "bar layer");
	itow(m->scene_img[VM][26].img, 0, 0, "processus layer");
	display_arene(m, v, 0, 0);
	display_player_name(m, v);
	vm_load(&m->scene_img[0][0]);
	return (1);
}
