files = so_long load_map show_move check_map check_path move error

sources = $(foreach buffer, $(files), sources/$(buffer).c)

libft = libft/libft.a

gnl = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MLX42 = MLX42/build/libmlx42.a

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(sources) $(libft) $(MLX42)
	$(CC) $(CFLAGS) $(sources) $(gnl) $(libft) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

$(libft):
	make -C libft

$(libft)re:
	make -C libft re

$(libft)clean:
	make -C libft clean

$(libft)fclean:
	make -C libft fclean

$(MLX42):
	cd MLX42 && cmake -B build && make -C build

$(MLX42)re:
	cd MLX42 && rm -rf build && cmake -B build && make -C build

$(MLX42)clean:
	rm -rf MLX42/build

clean: $(libft)clean $(MLX42)clean

fclean: $(libft)fclean $(MLX42)clean
	rm -rf $(NAME)

re: fclean $(libft)re $(MLX42)re all

debug: all
	$(CC) $(CFLAGS) $(sources) $(gnl) $(libft) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g3

.PHONY: all clean fclean re debug
