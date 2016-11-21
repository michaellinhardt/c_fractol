#include "ft_corewar.h"

static void	ft_init_instructions_comment(t_instructions *inst)
{
	ft_memcpy(inst[1].comment, "alive", 5);
	ft_memcpy(inst[2].comment, "load", 2);
	ft_memcpy(inst[3].comment, "store", 2);
	ft_memcpy(inst[4].comment, "addition", 3);
	ft_memcpy(inst[5].comment, "soustraction", 3);
	ft_memcpy(inst[6].comment, "et (and  r1, r2, r3   r1&r2 -> r3", 3);
	ft_memcpy(inst[7].comment, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 2);
	ft_memcpy(inst[8].comment, "ou (xor  r1, r2, r3   r1^r2 -> r3", 3);
	ft_memcpy(inst[9].comment, "jump if zero", 4);
	ft_memcpy(inst[10].comment, "load index", 3);
	ft_memcpy(inst[11].comment, "store index", 3);
	ft_memcpy(inst[12].comment, "fork", 4);
	ft_memcpy(inst[13].comment, "long load", 3);
	ft_memcpy(inst[14].comment, "long load index", 4);
	ft_memcpy(inst[15].comment, "long forkk", 5);
	ft_memcpy(inst[16].comment, "aff", 3);
}

static void	ft_init_instructions_flags_ocp(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].flag_ocp = 0;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 0;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 0;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 1;
	inst[i++].flag_ocp = 0;
	inst[i++].flag_ocp = 1;
}

static void	ft_init_instructions_flags_a_definir(t_instructions *inst)
{
	int i;

	i = 1;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 0;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 1;
	inst[i++].flag_size_ind = 0;
}

static void	ft_init_instructions_fonctions(t_instructions *inst)
{
	int i;

	i = 0;
	inst[i++].f_instructions = 0;
	inst[i++].f_instructions = ft_instructions_live;
	inst[i++].f_instructions = ft_instructions_ld;
	inst[i++].f_instructions = ft_instructions_st;
	inst[i++].f_instructions = ft_instructions_add;
	inst[i++].f_instructions = ft_instructions_sub;
	inst[i++].f_instructions = ft_instructions_and;
	inst[i++].f_instructions = ft_instructions_or;
	inst[i++].f_instructions = ft_instructions_xor;
	inst[i++].f_instructions = ft_instructions_zjmp;
	inst[i++].f_instructions = ft_instructions_ldi;
	inst[i++].f_instructions = ft_instructions_sti;
	inst[i++].f_instructions = ft_instructions_fork;
	inst[i++].f_instructions = ft_instructions_lld;
	inst[i++].f_instructions = ft_instructions_lldi;
	inst[i++].f_instructions = ft_instructions_lfork;
	inst[i++].f_instructions = ft_instructions_aff;
}

void		ft_init_instructions(t_instructions *inst)
{
	ft_init_instructions_name(inst);
	ft_init_instructions_nbr_args(inst);
	ft_init_instructions_types_arg_zero(inst);
	ft_init_instructions_types_arg_un(inst);
	ft_init_instructions_types_arg_deux(inst);
	ft_init_instructions_cycles(inst);
	ft_init_instructions_comment(inst);
	ft_init_instructions_flags_ocp(inst);
	ft_init_instructions_flags_a_definir(inst);
	ft_init_instructions_fonctions(inst);
}
