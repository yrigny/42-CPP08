CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

INCLUDE = MutantStack.hpp MutantStack.tpp

OBJ = $(SRC:.cpp=.o)

NAME = ex02

GREEN = \e[1;32m

NONE = \e[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
