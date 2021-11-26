#include "so_long.h"
#include <stdio.h>

t_tool	change_map_checker1(int code, t_tool tool)
{
	if (code == 1)
	{
		tool.moves++;
		tool.map[tool.y_position][tool.x_position] = '0';
		if (tool.map[tool.y_position - 1][tool.x_position] == 'C')
			tool.c_count--;
		tool.map[tool.y_position - 1][tool.x_position] = 'P';
		printf("The current number of moves = %d\n", tool.moves);
	}
	if (code == 2)
	{
		tool.moves++;
		tool.map[tool.y_position][tool.x_position] = '0';
		if (tool.map[tool.y_position][tool.x_position - 1] == 'C')
			tool.c_count--;
		tool.map[tool.y_position][tool.x_position - 1] = 'P';
		printf("The current number of moves = %d\n", tool.moves);
	}
	return (tool);
}

t_tool	change_map_checker2(int code, t_tool tool)
{
	if (code == 3)
	{
		tool.moves++;
		tool.map[tool.y_position][tool.x_position] = '0';
		if (tool.map[tool.y_position + 1][tool.x_position] == 'C')
			tool.c_count--;
		tool.map[tool.y_position + 1][tool.x_position] = 'P';
		printf("The current number of moves = %d\n", tool.moves);
	}
	if (code == 4)
	{
		tool.moves++;
		tool.map[tool.y_position][tool.x_position] = '0';
		if (tool.map[tool.y_position][tool.x_position + 1] == 'C')
			tool.c_count--;
		tool.map[tool.y_position][tool.x_position + 1] = 'P';
		printf("The current number of moves = %d\n", tool.moves);
	}
	return (tool);
}
