SRC =	memory.c 	moves.c \
	ops_list.c	parse.c \
	sort.c		sort_utils.c \
	parse_utils.c	stack_utils.c

PUSH_SWAP_SRC = push_swap.c

CHECKER_SRC = checker.c

OBJ_DIR = dist

OBJ = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}
PUSH_SWAP_OBJ = ${addprefix ${OBJ_DIR}/, ${PUSH_SWAP_SRC:.c=.o}}
CHECKER_OBJ = ${addprefix ${OBJ_DIR}/, ${CHECKER_SRC:.c=.o}}

CC = cc

CCFLAGS = -Wall -Wextra -Werror

NAME = push_swap

CHECKER = checker

LIBFT_DIR = ./libft/

LIBFT = libft.a

${OBJ_DIR}/%.o: %.c
	${CC} ${CCFLAGS} -c $< -o $@

${NAME}: ${LIBFT} ${OBJ_DIR} ${OBJ} ${PUSH_SWAP_OBJ}
	${CC} ${CCFLAGS} ${OBJ} ${PUSH_SWAP_OBJ} ${LIBFT} -o ${NAME}

${OBJ_DIR}:
	mkdir ${OBJ_DIR}

${LIBFT}:
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}${LIBFT} ${LIBFT}

all: ${NAME}

bonus: ${LIBFT} ${OBJ_DIR} ${OBJ} ${CHECKER_OBJ}
	${CC} ${CCFLAGS} ${OBJ} ${CHECKER_OBJ} ${LIBFT} -o ${CHECKER}

clean:
	rm -rf ${OBJ_DIR}
	make clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME} ${CHECKER}
	rm -rf ${LIBFT}
	make fclean -C ${LIBFT_DIR}

re: fclean all

PHONY: all clean fclean re push_swap libft.a dist
