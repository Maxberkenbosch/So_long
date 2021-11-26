#include "so_long.h"
#include "./mlx/mlx.h"
#include <stdio.h>

void	exit_game(t_tool tool, char *str, int release)
{
	int	i;

	i = 0;
	printf("%s\n", str);
	if (release == 1)
	{
		while (i < tool.window_height)
		{
			free(tool.map[i]);
			i++;
		}
		free(tool.map);
	}
	exit (0);
}
