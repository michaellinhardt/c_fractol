#include "ft_fractol.h"

int		mouseo_hook(int x, int y, t_data *d)
{
	d->mlx.input.mo_x = x;
	d->mlx.input.mo_y = y;
	if (d->mlx.input.mlast_x == 0)
	{
		d->mlx.input.mlast_x = x;
		d->mlx.input.mlast_y = y;
		return (0);
	}
	d->mlx.input.move_x = x - d->mlx.input.mlast_x;
	d->mlx.input.move_y = y - d->mlx.input.mlast_y;
	d->mlx.input.mlast_x = x;
	d->mlx.input.mlast_y = y;
	data()->mlx.loopstop = loop(1) + 1;
	return (0);
}

int		keyr_hook(int key, t_data *d)
{
	if (key == 53)
		exit1(0, d, "by pressing echap");
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

void	mouse_check_img(t_dmlx *m, int btn, t_img *img, int i)
{
	while ( m->scene_img[m->scene][++i].img )
	{
		img = &m->scene_img[0][i];
		if (m->input.mode == 0
		&& (img->mouse_btn == 3 || (img->mouse_btn == btn))
		&& (m->input.mr_x >= img->top[0] && m->input.mr_x <= img->bot[0])
		&& (m->input.mr_y >= img->top[1] && m->input.mr_y <= img->bot[1]))
			img->mouse_action();
	}
}

int		mouser_hook(int btn, int x, int y, t_data *d)
{
	(btn == 1) ? d->mlx.input.mleft = 0 : 0;
	(btn == 2) ? d->mlx.input.mright = 0 : 0;
	d->mlx.input.mr_x = x;
	d->mlx.input.mr_y = y;
	mouse_check_img(&data()->mlx, btn, (t_img *)NULL, -1);
	return (0);
}
