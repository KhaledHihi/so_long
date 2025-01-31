NAME = so_long

CFLAGS = -Wall -Wextra -Werror

SRC =

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all : $(NAME)

%.o: %.c
	cc -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJ)
