#include "so_long.h"

t_tool	exit_strategy1(int code, t_tool tool)
{
	if (code == 1)
	{
		if (tool.map[tool.y_position - 1][tool.x_position] == 'E')
			exit_game(tool, "Congrats! You've completed the game!", 2);
		if (tool.map[tool.y_position - 1][tool.x_position] != '1')
		{	
			tool.moves++;
			tool.map[tool.y_position][tool.x_position] = '0';
			tool.map[tool.y_position - 1][tool.x_position] = 'P';
			printf("The current number of moves = %d\n", tool.moves);
		}
	}
	if (code == 2)
	{
		if (tool.map[tool.y_position][tool.x_position - 1] == 'E')
			exit_game(tool, "Congrats! You've completed the game!", 2);
		if (tool.map[tool.y_position][tool.x_position - 1] != '1')
		{
			tool.moves++;
			tool.map[tool.y_position][tool.x_position] = '0';
			tool.map[tool.y_position][tool.x_position - 1] = 'P';
			printf("The current number of moves = %d\n", tool.moves);
		}
	}
	return (tool);
}

t_tool	exit_strategy2(int code, t_tool tool)
{
	if (code == 3)
	{
		if (tool.map[tool.y_position + 1][tool.x_position] == 'E')
			exit_game(tool, "Congrats! You've completed the game!", 2);
		if (tool.map[tool.y_position + 1][tool.x_position] != '1')
		{
			tool.moves++;
			tool.map[tool.y_position][tool.x_position] = '0';
			tool.map[tool.y_position + 1][tool.x_position] = 'P';
		}
	}
	if (code == 4)
	{
		if (tool.map[tool.y_position][tool.x_position + 1] == 'E')
			exit_game(tool, "Congrats! You've completed the game!", 2);
		if (tool.map[tool.y_position][tool.x_position + 1] != '1')
		{
			tool.moves++;
			tool.map[tool.y_position][tool.x_position] = '0';
			tool.map[tool.y_position][tool.x_position + 1] = 'P';
			printf("The current number of moves = %d\n", tool.moves);
		}
	}
	return (tool);
}
