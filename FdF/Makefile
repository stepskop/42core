SRCS =	main.c draw.c parse.c draw_utils.c \
	parse_utils.c lifecycle.c hooks.c \
	line.c matrix.c

OBJ_DIR = ./dist/

OBJ = $(addprefix $(OBJ_DIR), ${SRCS:.c=.o})

NAME = fdf

LIBFT = libft

MLX = mlx

$(OBJ_DIR)%.o: %.c $(MLX) $(LIBFT) $(OBJ_DIR)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -Ilibft -O3 -c $< -o $@

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(OBJ) -Lmlx -lmlx_Linux -Llibft -lft -L/usr/lib -Imlx -Ilibft -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	make -C ./mlx/ all

$(LIBFT):
	make -C ./libft/

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	make -C ./mlx/ clean
	make -C ./libft/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C ./libft/ fclean
	rm -rf fdf

re: fclean all

.PHONY: fdf mlx libft all clean fclean re
