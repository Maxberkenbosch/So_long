#include "so_long.h"

t_tool	map_checker(t_tool tool)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tool.window_height)
	{
		j = 0;
		while (j < tool.window_width)
		{
			tool = character_counter(tool.map[i][j], tool);
			if (tool.map[i][j] != '1' && tool.map[i][j] != '0' &&
			tool.map[i][j] != 'C' && tool.map[i][j] != 'P' &&
			tool.map[i][j] != 'E')
				exit_game(tool, "There is a false character in your map", 1);
			j++;
		}
		i++;
	}
	if (tool.c_count < 1 || tool.e_count < 1 || tool.p_count != 1)
		exit_game(tool, \
		"Error, map contains the wrong amount characters", 1);
	border_checker(tool);
	return (tool);
}

void	border_checker(t_tool tool)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tool.window_height)
	{
		j = 0;
		while (j < tool.window_width)
		{
			if ((i == 0 || i == tool.window_height - 1)
				&& tool.map[i][j] != '1')
				exit_game(tool, "The border is not complete", 1);
			else if (tool.map[i][0] != '1' ||
					tool.map[i][tool.window_width - 1] != '1')
				exit_game(tool, "Error, the border is not complete", 1);
			j++;
		}
		i++;
	}
	check_rectangular(tool);
}

t_tool	character_counter(char c, t_tool tool)
{
	if (c == 'C')
		tool.c_count++;
	if (c == 'E')
		tool.e_count++;
	if (c == 'P')
		tool.p_count++;
	return (tool);
}

void	check_rectangular(t_tool tool)
{
	int	i;

	i = 0;
	while (i < tool.window_height)
	{
		if ((int)ft_strlen(tool.map[i]) != tool.window_width && \
			i != tool.window_height - 1)
			exit_game(tool, "Error, the map isn't a rectangle", 1);
		else if (((int)ft_strlen(tool.map[i]) - 1) != tool.window_width && \
			i == tool.window_height - 1)
			exit_game(tool, "Error, the map isn't a rectangle", 1);
		i++;
	}
}
