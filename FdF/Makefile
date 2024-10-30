SRC_FILES =	main.c draw.c parse.c draw_utils.c \
		parse_utils.c lifecycle.c hooks.c \
		line.c matrix.c math_utils.c colors.c

OBJ_DIR = ./dist/

SRC_DIR = ./src/

OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

NAME = fdf

LIBFT = libft.a

MLX_DIR = ./mlx/

MLX = $(MLX_DIR)/libmlx_Linux.a

CC = cc

FLAGS = -Wall -Werror -Wextra

HEADERS = src/fdf.h

$(NAME): $(MLX) $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx -Llibft -lft -lmlx -Imlx -Ilft -I./src/ -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	make -C ./libft/

$(MLX):
	git submodule init
	git submodule update
	make -C $(MLX_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(FLAGS) -I./src/ -c $< -o $@

all: $(NAME)

clean:
	make -C ./mlx/ clean
	make -C ./libft/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C ./libft/ fclean
	rm -rf fdf

re: fclean all

.PHONY: all clean fclean re
