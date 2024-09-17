SRC = ${wildcard ft_*.c}

OBJ = ${SRC:.c=.o}

INCLUDES = libft.h

CCLAGS = cc -Wall -Werror -Wextra

NAME = libft.a

.c.o:
	${CCLAGS} -c -I ${INCLUDES} $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	ar rc ${NAME} *.o

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all