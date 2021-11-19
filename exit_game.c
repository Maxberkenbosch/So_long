#include "so_long.h"

void	exit_game(t_tool tool, char *str, int release)
{
	int	i;

	i = 0;
	printf("%s\n", str);
	if (release == 1 || release == 2)
	{
		while (i < tool.window_height)
		{
			free(tool.map[i]);
			i++;
		}
		free(tool.map);
	}
	if (release == 2)
		mlx_destroy_window(tool.mlx, tool.win);
	exit (0);
}
