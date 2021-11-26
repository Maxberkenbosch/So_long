#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct tool {
	char	**map;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		window_width;
	int		window_height;
	int		x_position;
	int		y_position;
	char	*water;
	char	*chicken;
	char	*rock;
	char	*bird;
	char	*chest;
	char	*chest_open;
	void	*mlx;
	void	*win;
	int		moves;
	int		read_return;
	int		words;
	char	*ch;
	char	*str;
	int		c_count;
	int		e_count;
	int		p_count;
}				t_tool;

//map
t_tool	read_map(t_tool tool, char *text);
t_tool	make_map(t_tool tool);
t_tool	get_asset(t_tool assets);
int		render_next_frame(t_tool *tool);
t_tool	free_ch_str_fd(t_tool tool, int fd);

//game play
int		key_hook(int keycode, t_tool *tool);
int		close_screen(int key, void *param);
t_tool	change_map1(int code, t_tool tool);
t_tool	change_map2(int code, t_tool tool);
t_tool	move(int keycode, t_tool tool);

//utils
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

//split
char	**ft_split(char const *s, char c, int *words, t_tool tool);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//join
char	*ft_strjoin(char *s1, char const *s2, t_tool tool);

//calloc
void	*ft_calloc(size_t count, size_t size, t_tool tool);
void	*ft_memset(void *b, int c, size_t len);

//map checker
t_tool	character_counter(char c, t_tool tool);
t_tool	map_checker(t_tool tool);
void	border_checker(t_tool tool);
void	check_rectangular(t_tool tool);

//make_map_checker
t_tool	make_map_checker(t_tool tool);

//change_map_checker
t_tool	change_map_checker1(int code, t_tool tool);
t_tool	change_map_checker2(int code, t_tool tool);

//exit_strategy
t_tool	exit_strategy1(int code, t_tool tool);
t_tool	exit_strategy2(int code, t_tool tool);

//exit
void	exit_game(t_tool tool, char *str, int release);

//check_argv
void	check_argv(char *argv[], t_tool tool);

#endif
