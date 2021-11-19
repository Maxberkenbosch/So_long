#include "so_long.h"

int	key_hook(int keycode, t_tool *tool)
{
	*tool = move(keycode, *tool);
	return (keycode);
}

t_tool	move(int keycode, t_tool tool)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == 13)
		tool = change_map1(1, tool);
	if (keycode == 0)
		tool = change_map1(2, tool);
	if (keycode == 1)
		tool = change_map2(3, tool);
	if (keycode == 2)
		tool = change_map2(4, tool);
	if (tool.c_count == 0)
		tool.chest = tool.chest_open;
	tool = make_map(tool);
	return (tool);
}

int	close_screen(int key, void *param)
{
	(void)key;
	(void)param;
	exit(0);
	return (0);
}

t_tool	change_map1(int code, t_tool tool)
{
	if (code == 1)
	{
		if (tool.c_count == 0)
			tool = exit_strategy1(1, tool);
		else if (tool.map[tool.y_position - 1][tool.x_position] != '1' &&
			tool.map[tool.y_position - 1][tool.x_position] != 'E')
			tool = change_map_checker1(1, tool);
	}
	if (code == 2)
	{
		if (tool.c_count == 0)
			tool = exit_strategy1(2, tool);
		else if (tool.map[tool.y_position][tool.x_position - 1] != '1' &&
			tool.map[tool.y_position][tool.x_position - 1] != 'E')
			tool = change_map_checker1(2, tool);
	}
	return (tool);
}

t_tool	change_map2(int code, t_tool tool)
{
	if (code == 3)
	{
		if (tool.c_count == 0)
			tool = exit_strategy2(3, tool);
		else if (tool.map[tool.y_position + 1][tool.x_position] != '1' &&
			tool.map[tool.y_position + 1][tool.x_position] != 'E')
			tool = change_map_checker2(3, tool);
	}
	if (code == 4)
	{
		if (tool.c_count == 0)
			tool = exit_strategy2(4, tool);
		else if (tool.map[tool.y_position][tool.x_position + 1] != '1' &&
			tool.map[tool.y_position][tool.x_position + 1] != 'E')
			tool = change_map_checker2(4, tool);
	}
	return (tool);
}
