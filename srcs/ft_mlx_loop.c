#include "ft_fractol.h"

int		loop(char etat)
{
	t_dmlx *m;

	m = &(data()->mlx);
	if (m->loop && m->loopstop != 0)
		return (1);
	else if (m->loop != etat)
	{
		m->loop = etat;
		if (etat == 1)
			l1(6, "LOOP STATUS", "-> 1");
		else
			l1(6, "LOOP STATUS", "-> 0");
	}
	return (1);
}

int		loop_hook(t_data *d)
{
	t_dmlx *m;


	m = &d->mlx;
	if (USLEEP_BOOL && m->loop == 0 && !usleep(USLEEP_TIME))
		return (0);
	if (m->loopstop != 0 && --m->loopstop < 1 && m->loop != 0)
		loop(0);
	scene_img(d, &d->mlx);
	scene(d, &d->mlx);
	return (0);
}
