# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 18:11:39 by dvidal-l          #+#    #+#              #
#    Updated: 2023/08/27 18:11:40 by dvidal-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= main.c atoi.c oper.c

OBJ = $(SRC:.c=.o)

HEAD = do-op

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = do-op

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	-rm -f $(OBJ) 

fclean:	clean
	-rm -f $(NAME) 

re: fclean all

.PHONY:	all clean fclean re