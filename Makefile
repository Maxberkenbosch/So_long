FILES =	main.c\
		map.c\
		game_play.c\
		split.c\
		so_long_utils.c\
		str_join.c\
		calloc.c\
		make_map_checker.c\
		exit_strategy.c\
		exit_game.c\
		change_map_checker.c\
		map_checker.c

OBJS = $(FILES:.c=.o)

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

CC = gcc

%.o : %.c
	@$(CC) $(CFLAGS) -c $<
	@echo "Compiling $<"

$(NAME): $(OBJS)
	$(CC) -Imlx $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "Removing object files"

fclean: clean
	rm -rf $(NAME)

re: fclean all
