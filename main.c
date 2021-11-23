#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_tool	tool;

	tool.moves = 0;
	if (argc != 2)
		exit_game(tool, "You entered the wrong amount of arguments", 0);
	check_argv(argv, tool);
	tool.mlx = mlx_init();
	tool = get_asset(tool);
	tool = read_map(tool, argv[1]);
	mlx_hook(tool.win, 17, 0, close_screen, (void *)0);
	mlx_loop(tool.mlx);
	return (0);
}
