# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 14:35:21 by dvidal-l          #+#    #+#              #
#    Updated: 2023/10/01 16:52:33 by dvidal-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c 
OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

NAME = libftprintf.a
CFLAGS = -g -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar -rcs $@ $(OBJ)

re: fclean all

clean:
	rm -f $(OBJ) 
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(LIBFT)
	make -C libft fclean

.PHONY: all re clean fclean