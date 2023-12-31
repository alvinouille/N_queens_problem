NAME	= theNQueen
SRC		= main.cpp board.cpp
OBJ		= $(SRC:.cpp=.o)
CC		= g++
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re