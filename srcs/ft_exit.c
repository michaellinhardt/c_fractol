/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 20:55:42 by mlinhard          #+#    #+#             */
/*   Updated: 2016/12/25 20:57:50 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	exitascii(t_data *d, int err, char *msg)
{
	if (!d->args.console)
		return ;
	ft_putstr("🎼  ╔═════════════════════════════════════════════════════════");
	ft_putendl("═════════════════╗");
	ft_printf(" %C ║ %s%-72s%s ║\n", ((err == 1) ? L'🚨' : L'🌙')
		, ((err == 1) ? "\e[91m" : "\e[96m"), msg, "\e[93m");
	ft_putstr("🎼  ╚═════════════════════════════════════════════════════════");
	ft_putendl("═════════════════╝");
}

int		exit1(int err, t_data *d, char *msg)
{
	free_data(d);
	if (d->args.console)
	{
		if (err != 0)
			ascii(ASC_EXIT_1);
		else
			ascii(ASC_EXIT_0);
		exitascii(d, err, msg);
	}
	else if (!d->args.console && err)
		ft_printf("%s\n", msg);
	exit(err);
	return (1);
}

int		exit2(int err, t_data *d, char *del, char *msg)
{
	ft_strdel(&del);
	exit1(err, d, msg);
	return (1);
}
