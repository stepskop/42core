SRC = main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			PresidentialPardonForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			Intern.cpp
OBJ_DIR = ./build/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
CC = c++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = program

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%o: %cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
