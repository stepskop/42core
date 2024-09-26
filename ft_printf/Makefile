SRCS = srcs/ft_printf.c srcs/ft_print_base.c srcs/ft_print_utils.c

BSRCS = srcs_bonus/ft_printf_bonus.c srcs_bonus/printf_hex_bonus.c \
	srcs_bonus/print_utils_bonus.c srcs_bonus/parse_flags_bonus.c \
	srcs_bonus/flags_utils_bonus.c srcs_bonus/printf_chr_bonus.c \
	srcs_bonus/printf_str_bonus.c srcs_bonus/printf_nbr_bonus.c \
	srcs_bonus/printf_udc_bonus.c
OBJ = ${SRCS:%c=%o}

BOBJ = ${BSRCS:%c=%o} 

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

bonus: ${LIBFT} ${BOBJ}
	ar rcs ${NAME} ${BOBJ}

clean:
	make clean -C ${LIBFT_DIR}
	rm -f ${BOBJ}
	rm -f ${OBJ}

fclean: clean
	make fclean -C ${LIBFT_DIR}
	rm -f ${NAME}
	rm -f ${LIBFT}

re: fclean all
