#include "ft_fractol.h"

void		scene(t_data *d, t_dmlx *m)
{
	if (m->scene == FRACTOL)
		scene_1_fractol(d, m, -1);
	else if (m->scene == INTRO)
		scene_0_intro(d, m);
	(void)d;
}
