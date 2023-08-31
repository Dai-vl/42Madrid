SRC	= ft_display_file.c
NAME = ft_display_file
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) $(SRC) -c
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: fclean all fclean re