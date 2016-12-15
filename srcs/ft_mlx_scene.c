#include "ft_fractol.h"

void		scene(t_data *d, t_dmlx *m)
{
	(void)d;
	if (m->scene == FRACTOL);
	else if (m->scene == FRACTOL_INIT)
		;
	else if (m->scene == INTRO_LOAD)
		scene_0_intro(d, m);
	else if (m->scene == INTRO_MENU)
		;
	else if (m->scene == INTRO_OUT)
		;
}
