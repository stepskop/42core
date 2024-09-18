SRC = ${filter-out ${wildcard ft_lst*.c}, ${wildcard ft_*.c}}

BSRC = ${wildcard ft_lst*.c}

OBJ = ${SRC:.c=.o}

BOBJ = ${BSRC:.c=.o}

INCLUDES = libft.h

CCLAGS = cc -Wall -Werror -Wextra

NAME = libft.a

.c.o:
	${CCLAGS} -c -I ${INCLUDES} $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	ar rc ${NAME} *.o

all: ${NAME}

bonus: ${OBJ} ${BOBJ}
	ar rc ${NAME} *.o

clean:
	rm -f ${OBJ} ${BOBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all