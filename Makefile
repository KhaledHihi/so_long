NAME = so_long

CFLAGS = -Wall -Wextra -Werror

SRC = main.c helper_files/check_file_name.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJ)
