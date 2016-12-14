/*
** GENERE L'AFFICHAGE DES BAR DE LIVE
*/
#include "ft_corewar.h"

static void	put_open_img(t_img *img, t_img *open, int x, int y)
{
	int			*popen;
	int			*pimg;

	popen = (int *)open->str;
	pimg = (int *)img->str;
	img->i = (y * WIN_X + x) - 1;
	y = -1;
	while (++y < BAROPENY)
	{
		x = -1;
		while (++x < BAROPENX)
		{
			pimg[++(img->i)] = popen[y * BAROPENX + x];
			img->str[img->i * 4 + 3] = BARALIVEPROCALPHA;
		}
		img->i = img->i - x + WIN_X;
	}
}

static void	put_close_img(t_img *img, t_img *open, int x, int y)
{
	int			*popen;
	int			*pimg;

	popen = (int *)open->str;
	pimg = (int *)img->str;
	img->i = (y * WIN_X + x) - 1;
	y = -1;
	while (++y < BARCLOSEY)
	{
		x = -1;
		while (++x < BARCLOSEX)
		{
			pimg[++(img->i)] = popen[y * BARCLOSEX + x];
			img->str[img->i * 4 + 3] = BARALIVEPROCALPHA;
		}
		img->i = img->i - x + WIN_X;
	}
}

static void	put_mid_img(t_dvm *v, t_img *img, int i, int posx)
{
	int			*pmid;
	int			*pimg;
	double		nbr;
	int			y;
	double		percent;

	pimg = (int *)img->str;
	while (++i < MAX_PLAYERS)
	{
		if (!(v->p[i].total_proc_alive))
			continue ;
		pmid = (int *)data()->mlx.scene_img[VM][BARIMGID + (i * 3) + 1].str;
		percent = ((double)v->p[i].total_proc_alive / (double)v->nbr_proc);
		nbr = ((double)BARPROCALIVESIZE) * percent;
		while (--nbr > -2 && ++posx <= BARPROCALIVESIZE && (y = -1))
		{
			img->i = (BARPROCALIVEY * WIN_X) + BARPROCALIVEX + BAROPENX + posx;
			while (++y < BAROPENY)
			{
				pimg[(img->i)] = pmid[y];
				img->str[img->i * 4 + 3] = BARALIVEPROCALPHA;
				img->i = img->i + WIN_X;
			}
		}
	}
}

void		display_bar_proc(t_dmlx *m, t_dvm *v, t_img *img, int i)
{
	int		popen;
	int		pclose;

	i = -1;
	popen = -1;
	pclose = -1;
	while (++i < MAX_PLAYERS)
		if (v->p[i].total_proc_alive > 0 && ((pclose = i) + 1) && popen == -1)
			popen = i;
	put_open_img(img, &m->scene_img[VM][BARIMGID + (popen * 3)]
	, BARPROCALIVEX, BARPROCALIVEY);
	put_mid_img(v, img, -1, -1);
	put_close_img(img, &m->scene_img[VM][BARIMGID + (pclose * 3) + 2]
	, BARPROCALIVEX + BARPROCALIVESIZE, BARPROCALIVEY);
}
