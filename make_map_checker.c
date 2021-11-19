#include "so_long.h"

t_tool	make_map_checker(t_tool tool)
{
	if (tool.map[tool.y][tool.x] == '1')
		mlx_put_image_to_window(tool.mlx, tool.win, \
		tool.rock, tool.x * 32, tool.y * 32);
	if (tool.map[tool.y][tool.x] == 'C')
		mlx_put_image_to_window(tool.mlx, tool.win, \
		tool.chicken, tool.x * 32, tool.y * 32);
	if (tool.map[tool.y][tool.x] == 'P')
	{
		tool.x_position = tool.x;
		tool.y_position = tool.y;
		mlx_put_image_to_window(tool.mlx, tool.win, \
		tool.bird, tool.x * 32, tool.y * 32);
	}
	if (tool.map[tool.y][tool.x] == 'E')
		mlx_put_image_to_window(tool.mlx, tool.win, \
		tool.chest, tool.x * 32, tool.y * 32);
	return (tool);
}
