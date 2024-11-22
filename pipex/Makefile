SRC_FILES = main.c
SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = ./dist/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

NAME = pipex

CC = cc
CCFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
