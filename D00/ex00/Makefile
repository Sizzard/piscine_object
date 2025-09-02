CC = c++
NAME = bank
CPPFLAGS =  -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Bank.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Bank.hpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re