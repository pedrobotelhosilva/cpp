NAME = bureaucrat
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
src = main.cpp Bureaucrat.cpp
OBJ_F = ./obj
obj = $(src:%.cpp=$(OBJ_F)/%.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(obj)
	$(CC) $(CFLAGS) $(obj) -o $(NAME)

$(OBJ_F)/%.o: %.cpp
	mkdir -p $(OBJ_F)
	$(CC) $(CFLAGS) $(SRC) -c $< -o $@ 

clean:
	$(RM) $(obj) $(OBJ_F)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.Phony: clean fclean re all