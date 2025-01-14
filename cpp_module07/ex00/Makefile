NAME = whatever
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
OBJ_F = ./obj
SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=$(OBJ_F)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_F)/%.o: %.cpp
	mkdir -p $(OBJ_F)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_F)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all