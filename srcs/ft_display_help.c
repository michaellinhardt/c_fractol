#include "ft_fractol.h"

void	ft_display_help(void)
{
	ft_putendl("  Syntax:\t./fractal <options> <fractal name>");
	ft_putendl("  Options:");
	ft_putendl("  -l\t\tdisplay log system");
	ft_putendl("  -s\t\tenable sound");
	ft_putendl("  -i\t\tskip intro");
	ft_putendl("  Fractal list:");
	ft_putendl("  \t\tJulia");
	exit(0);
}
