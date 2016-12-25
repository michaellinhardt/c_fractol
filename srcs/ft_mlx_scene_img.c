/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_scene_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 20:59:10 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 20:59:10 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			scene_img_file(t_dmlx *m, DIR *dir, struct dirent *f, char *path)
{
	char	*folder;
	char	*file;

	ft_printf("%!%sxpm/%s", &folder, data()->folder, path);
	if (!(dir = opendir(folder)))
		exit2(1, data(), folder, "Cant open xpm sub dir.");
	while ((f = readdir(dir)))
	{
		if (!ft_isdigit(f->d_name[0]) || !ft_strstr(f->d_name, ".xpm"))
			continue ;
		ft_printf("%!%s/%s", &file, folder, f->d_name);
		l1(1, f->d_name, "   loading xpm file");
		m->scene_img[m->scene][ft_atoi(f->d_name)].img = mlx_xpmtostruct(m
			, &m->scene_img[m->scene][ft_atoi(f->d_name)], file);
		ft_strdel(&file);
	}
	closedir(dir);
	ft_strdel(&folder);
	return (1);
}

void		scene_img_folder(t_dmlx *m, DIR *dir, struct dirent *f)
{
	char	*folder;

	ft_printf("%!%sxpm", &folder, data()->folder);
	if (!(dir = opendir(folder)))
		exit2(1, data(), folder, "Cant open xpm dir.");
	while ((f = readdir(dir)))
	{
		if (!ft_strstr(f->d_name, ".xpm"))
			continue ;
		else if (ft_atoi(f->d_name) == m->scene && l1(1, f->d_name
			, "loading xpm from scene folder") && scene_img_file(m
			, (DIR *)NULL, (struct dirent *)NULL, f->d_name))
			break ;
	}
	closedir(dir);
	ft_strdel(&folder);
}

void		scene_layout_init(t_img *i)
{
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		i->str[i->i] = 255;
		i->str[i->i + 1] = 255;
		i->str[i->i + 2] = 255;
		i->str[i->i + 3] = 255;
	}
}

void		scene_img(t_data *d, t_dmlx *m)
{
	(void)d;
	if (m->img_isload[m->scene] == 1)
		return ;
	scene_img_folder(m, (DIR *)NULL, (struct dirent *)NULL);
	scene_img_init(d, m);
	m->img_isload[m->scene] = 1;
}
