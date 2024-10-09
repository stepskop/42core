NAME = minitalk
CLIENT = client
SERVER = server

OBJ_DIR = ./dist

CLIENT_DIR = ./src/client
SERVER_DIR = ./src/server

CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_OBJ = ${addprefix ${OBJ_DIR}/${CLIENT}/, ${CLIENT_SRC:.c=.o}}
SERVER_OBJ = ${addprefix ${OBJ_DIR}/${SERVER}/, ${SERVER_SRC:.c=.o}}

LIBFT = libft.a
LIBFT_DIR = ./libft/

CCFLAGS = -Wall -Werror -Wextra

CC = cc

${NAME}: ${OBJ_DIR} ${LIBFT} ${CLIENT} ${SERVER}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}/${SERVER}
	mkdir -p ${OBJ_DIR}/${CLIENT}

${CLIENT}: ${OBJ_DIR} ${CLIENT_OBJ} ${LIBFT}
	${CC} ${CCFLAGS} ${CLIENT_OBJ} ${LIBFT} -o ${CLIENT}

${SERVER}: ${OBJ_DIR} ${SERVER_OBJ} ${LIBFT}
	${CC} ${CCFLAGS} ${SERVER_OBJ} ${LIBFT} -o ${SERVER}

${OBJ_DIR}/${CLIENT}/%.o: ${CLIENT_DIR}/%.c
	${CC} ${CCFLAGS} -c $< -o $@

${OBJ_DIR}/${SERVER}/%.o: ${SERVER_DIR}/%.c
	${CC} ${CCFLAGS} -c $< -o $@

${LIBFT}:
	make bonus -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}${LIBFT} ${LIBFT}

all: ${NAME}

clean:
	rm -rf ${OBJ_DIR}
	make clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${LIBFT} 
	rm -rf ${CLIENT} 
	rm -rf ${SERVER}
	make fclean -C ${LIBFT_DIR}

re: fclean all
