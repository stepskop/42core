SRC = 	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c\
	ft_isascii.c	ft_isprint.c	ft_strlen.c\
	ft_memset.c	ft_bzero.c	ft_memcpy.c\
	ft_memmove.c	ft_strlcpy.c	ft_strlcat.c\
	ft_toupper.c	ft_tolower.c	ft_strchr.c\
	ft_strrchr.c	ft_strncmp.c	ft_memchr.c\
	ft_memcmp.c	ft_strnstr.c	ft_atoi.c\
	ft_calloc.c	ft_strdup.c	ft_substr.c\
	ft_strjoin.c	ft_strtrim.c	ft_split.c\
	ft_itoa.c	ft_strmapi.c	ft_striteri.c\
	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c\
	ft_putnbr_fd.c	ft_lstnew.c	ft_lstadd_front.c\
	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c\
	ft_lstmap.c	ft_realloc.c	get_next_line.c\
	ft_atoi_base.c

PRINTF_SRC = 	ft_printf/flags_utils.c	ft_printf/parse_flags.c\
		ft_printf/print_utils.c	ft_printf/printf_nbr.c\
		ft_printf/printf_chr.c	ft_printf/printf_hex.c\
		ft_printf/printf_str.c	ft_printf/printf_udc.c\
		ft_printf/ft_printf.c

OBJ = ${SRC:%c=%o}

PRINTF_OBJ = ${PRINTF_SRC:%c=%o}

CCLAGS = cc -Wall -Werror -Wextra

NAME = libft.a

${NAME}: ${OBJ} ${PRINTF_OBJ}
	ar rc ${NAME} ${OBJ} ${PRINTF_OBJ}

%.o: %.c
	${CCLAGS} -c $< -o ${<:%c=%o}

all: ${NAME}

bonus: all

clean:
	rm -f ${OBJ} ${PRINTF_OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
