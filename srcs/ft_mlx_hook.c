#include "ft_fractol.h"

int		mouseo_hook(int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	d->mlx.input.mo_x = x;
	d->mlx.input.mo_y = y;
	return (0);
}

int		keyr_hook(int key, t_data *d)
{
	if (key == 53)
		exit1(0, d, "by pressing echap");
	else if (d->mlx.scene == INTRO_MENU)
		return (0 * (d->mlx.scene = INTRO_OUT));
	else if (d->mlx.scene == FRACTOL)
	{
	}
	return (0);
}

int		keyp_hook(int key, t_data *d)
{
	return (d->mlx.loop += 0 * key);
}

int		mousep_hook(int btn, int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	(btn == 1) ? d->mlx.input.mleft = 1 : 0;
	(btn == 2) ? d->mlx.input.mright = 1 : 0;
	return (0);
}

int		mouser_hook(int btn, int x, int y, t_data *d)
{
	(btn == 1) ? d->mlx.input.mleft = 0 : 0;
	(btn == 2) ? d->mlx.input.mright = 0 : 0;
	d->mlx.input.mr_x = x;
	d->mlx.input.mr_y = y;
	return (btn += 0);
}
