SRC	= ft_cat.c
NAME = ft_cat
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) $(SRC) -c
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: fclean all fclean re