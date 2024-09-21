SRCS = srcs/ft_printf.c srcs/ft_print_base.c srcs/ft_print_utils.c

OBJ = ${SRCS:%c=%o}

CCLAGS = cc -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT_DIR = ./libft/

LIBFT = libft.a

${NAME}: ${LIBFT} ${OBJ}
	ar rcs ${NAME} ${OBJ}

${LIBFT}:
	make bonus -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}${LIBFT} ${NAME}

%.o: %.c
	${CCLAGS} -c -I./includes $< -o ${<:%c=%o}

all: ${NAME}

clean:
	make clean -C ${LIBFT_DIR}
	rm -f ${OBJ}

fclean: clean
	make fclean -C ${LIBFT_DIR}
	rm -f ${NAME}
	rm -f ${LIBFT}

re: fclean all