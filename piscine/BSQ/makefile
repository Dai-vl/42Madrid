# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 15:22:11 by dvidal-l          #+#    #+#              #
#    Updated: 2023/08/30 15:22:19 by dvidal-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= main.c file_read.c solver.c utils_int.c utils_str.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = bsq

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	-rm -f $(OBJ) 

fclean:	clean
	-rm -f $(NAME) 

re: fclean all

.PHONY:	all clean fclean re
