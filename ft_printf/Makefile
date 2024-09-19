SRCS = srcs/ft_printf.c

OBJ = ${SRCS:%c=%o}

CCLAGS = cc -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT_DIR = ./libft/

LIBFT = libft.a

${NAME}: ${LIBFT} ${OBJ}
	ar rcs ${NAME} ${LIBFT_DIR}${LIBFT} ${OBJ}

${LIBFT}:
	make bonus -C ${LIBFT_DIR}

%.o: %.c
	${CCLAGS} -c -I./includes $< -o ${<:%c=%o}

all: ${NAME}

clean:
	make clean -C ${LIBFT_DIR}
	rm -f ${OBJ}

fclean: clean
	make fclean -C ${LIBFT_DIR}
	rm -f ${NAME}

re: fclean all