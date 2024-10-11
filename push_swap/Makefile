SRC =	memory.c moves.c	operations.c	parse.c \
		push_swap.c			sort.c			sort_utils.c \
		parse_utils.c		stack_utils.c

OBJ = ${SRC:.c=.o}

CC = cc

CCFLAGS = -Wall -Werror -Wextra

NAME = push_swap

LIBFT_DIR = ./libft/

LIBFT = libft.a

%.o: %.c
	${CC} ${CCFLAGS} -c $< -o $@

${NAME}: ${LIBFT} ${OBJ}
	${CC} ${CCFLAGS} ${OBJ} ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}${LIBFT} ${LIBFT}

all: ${NAME}

clean:
	rm -rf ${OBJ}
	make clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${LIBFT}
	make fclean -C ${LIBFT_DIR}

re: fclean all
