SRC	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
HEAD = ./includes
LIB = libft.a
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I$(HEAD)

$(LIB): $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)

.PHONY: fclean all fclean re
