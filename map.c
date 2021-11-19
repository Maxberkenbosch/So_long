#include "so_long.h"

t_tool	read_map(t_tool tool, char *text)
{
	int		fd;
	int		height;

	tool.read_return = 1;
	fd = open(text, O_RDONLY);
	tool.ch = calloc(2, 1);
	tool.str = calloc(1, 1);
	while (tool.read_return != 0)
	{
		tool.read_return = read(fd, tool.ch, 1);
		if (tool.read_return == -1)
			exit_game(tool, "Something went wrong while reading the file", 0);
		tool.str = ft_strjoin(tool.str, tool.ch, tool);
	}
	tool.map = ft_split(tool.str, '\n', &height, tool);
	tool = free_ch_str_fd(tool, fd);
	tool.window_height = height;
	tool.window_width = (ft_strlen(tool.map[0]));
	tool = map_checker(tool);
	tool.win = mlx_new_window(tool.mlx, tool.window_width * 32, \
	tool.window_height * 32, "Game!");
	tool = make_map(tool);
	mlx_loop_hook(tool.mlx, render_next_frame, &tool);
	return (tool);
}

t_tool	free_ch_str_fd(t_tool tool, int fd)
{
	free(tool.ch);
	free(tool.str);
	close(fd);
	return (tool);
}

t_tool	get_asset(t_tool tool)
{
	int	size;

	size = 32;
	tool.water = mlx_xpm_file_to_image(tool.mlx, \
	"./tool/water.xpm", &size, &size);
	tool.chicken = mlx_xpm_file_to_image(tool.mlx, \
	"./tool/chicken.xpm", &size, &size);
	tool.rock = mlx_xpm_file_to_image(tool.mlx, \
	"./tool/rock.xpm", &size, &size);
	tool.bird = mlx_xpm_file_to_image(tool.mlx, \
	"./tool/bird.xpm", &size, &size);
	tool.chest = mlx_xpm_file_to_image(tool.mlx, \
	"./tool/chest.xpm", &size, &size);
	tool.chest_open = mlx_xpm_file_to_image(tool.mlx, \
	"./tool/chest_open.xpm", &size, &size);
	return (tool);
}

t_tool	make_map(t_tool tool)
{
	tool.x = 0;
	tool.y = 0;
	while (tool.y < tool.window_height)
	{
		while (tool.x < tool.window_width)
		{
			mlx_put_image_to_window(tool.mlx, tool.win, \
			tool.water, tool.x * 32, tool.y * 32);
			if (tool.map[tool.y][tool.x] == '1')
				tool = make_map_checker(tool);
			if (tool.map[tool.y][tool.x] == 'C')
				tool = make_map_checker(tool);
			if (tool.map[tool.y][tool.x] == 'P')
				tool = make_map_checker(tool);
			if (tool.map[tool.y][tool.x] == 'E')
				tool = make_map_checker(tool);
			tool.x++;
		}
		tool.y++;
		tool.x = 0;
	}
	return (tool);
}

int	render_next_frame(t_tool *tool)
{
	mlx_key_hook(tool->win, key_hook, tool);
	return (0);
}
