#include "so_long.h"
void	check_argv(char *argv[], t_tool tool)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (argv[1][len -1] != 'r' && argv[1][len -2] != 'e' && \
	argv[1][len -3] != 'b' && argv[1][len -4] != '.')
		exit_game(tool, "The argument given isn't a .ber file", 0);
}