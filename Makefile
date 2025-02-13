NAME = so_long

CFLAGS = -Wall -Wextra -Werror

SRC = main.c helper_files/check_file_name.c get_next_line_/get_next_line.c get_next_line_/get_next_line_utils.c \
	check_map.c helper_files/clean.c helper_files/ft_strlen.c helper_files/flood_fill.c window.c helper_files/image_to_ptr.c\
	helper_files/check_walls.c helper_files/draw_map.c \

OBJ = $(SRC:.c=.o)

libmlx = minilibx-linux/libmlx_Linux.a

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(libmlx) -lXext -lX11 -lm printf/libftprintf.a

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
