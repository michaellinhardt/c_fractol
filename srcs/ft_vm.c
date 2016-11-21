/*
** GESTION DE LA VM
*/
#include "ft_corewar.h"

static void	vm_dump(t_dvm *v)
{
	l2(12, "BYE BYE", "dump cycle", v->cycle);
	ft_display_vm(v);
	ft_printf("Actual cycle: %d\n", v->cycle);
	ft_printf("Total proc: %d\n", v->nbr_proc);
	ft_printf("Cycle to die: %d\n", v->ctodie);
	ft_printf("Last live cycle: %d\n", v->last_live_cycle);
	ft_printf("Live current period: %d\n", v->nbr_live);
	ft_printf("Live current period player: %d\n", v->live_player);
	ft_printf("Max cheks value: %d\n", v->max_checks);
	exit1(0, data(), "dump order");
}

static void	ft_display_graphic(t_dvm *v)
{
	if (v->graphic)
		display(&(data()->mlx), v);
	if (v->dump <= v->cycle && v->dump != -1)
		vm_dump(v);
}

void		vm(t_dvm *v, int cperloop)
{
	while (--cperloop > -1)
	{
		if (v->graphic && v->pause && data()->mlx.input.up == 0
				&& !(v->pause_inc))
			break ;
		v->pause_inc = 0;
		v->cycle++;
		if (!gameloop(v) || !v->proc)
		{
			if (v->dump != -1)
				vm_dump(v);
			if (v->graphic && (data()->mlx.scene = END))
				return ;
			else
				exit3(0, data(), ABS(v->last_live));
		}
		else if (v->dump == v->cycle)
		{
			if (v->graphic)
				display(&(data()->mlx), v);
			vm_dump(v);
		}
	}
	ft_display_graphic(v);
}
