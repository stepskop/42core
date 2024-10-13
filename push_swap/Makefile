SRC =	memory.c 	moves.c \
	ops_list.c	parse.c \
	sort.c		sort_utils.c \
	parse_utils.c	stack_utils.c

PUSH_SWAP_SRC = push_swap.c

OBJ = ${SRC:.c=.o}

PUSH_SWAP_OBJ = ${PUSH_SWAP_SRC:.c=.o}

CC = cc

CCFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT_DIR = ./libft/

LIBFT = libft.a

CHECKER_SRC = checker.c

CHECKER_OBJ = ${CHECKER_SRC:.c=.o}

CHECKER = checker

%.o: %.c
	${CC} ${CCFLAGS} -c $< -o $@

${NAME}: ${LIBFT} ${OBJ} ${PUSH_SWAP_OBJ}
	${CC} ${CCFLAGS} ${OBJ} ${PUSH_SWAP_OBJ} ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}${LIBFT} ${LIBFT}

all: ${NAME}

bonus: ${LIBFT} ${OBJ} ${CHECKER_OBJ}
	${CC} ${CCFLAGS} ${OBJ} ${CHECKER_OBJ} ${LIBFT} -o ${CHECKER}

clean:
	rm -rf ${OBJ}
	make clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME} ${CHECKER}
	rm -rf ${LIBFT}
	make fclean -C ${LIBFT_DIR}

re: fclean all

PHONY: all clean fclean re push_swap libft.a
