SRC_FILES = main.c utils.c
SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = ./dist/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

BONUS_SRC_FILES = main.c
BONUS_SRC_DIR = ./src_bonus/
BONUS_SRCS = $(addprefix $(BONUS_SRC_DIR), $(BONUS_SRC_FILES))

BONUS_OBJ_DIR = ./dist_bonus/
BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_OBJ_FILES))

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

NAME = pipex

BONUS_NAME = pipex_bonus

CC = cc
CCFLAGS = -Wall -Werror -Wextra -g

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)

bonus: $(BONUS_OBJ_DIR) $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

clean:
	rm -rf $(BONUS_OBJ_DIR)
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(BONUS_NAME)
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
