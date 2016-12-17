#include "ft_fractol.h"

void		scene(t_data *d, t_dmlx *m)
{
	(void)d;
	if (m->scene == FRACTOL)
		;
	else if (m->scene == FRACTOL_INIT)
		exit1(0, d, "wip fractol_init code");
	else if (m->scene == INTRO)
		scene_0_intro(d, m);
}
