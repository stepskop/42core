
NAME = philo_bonus

SRC_FILES = main.c parse.c memory.c \
			actions.c routine.c time.c

SRC_DIR = ./src/

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = ./dist/

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

CC = cc
CCFLAGS = -Wall -Werror -Wextra -pthread -g

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%o: $(SRC_DIR)%c
	$(CC) $(CCFLAGS) -c $< -o $@


$(OBJ_DIR):
	mkdir $(OBJ_DIR)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
