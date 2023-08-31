# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 22:25:59 by dvidal-l          #+#    #+#              #
#    Updated: 2023/08/28 22:26:01 by dvidal-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
rm -f libft.a

cc -c -Wall -Werror -Wextra ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

ar rc libft.a *.o

rm -f *.o
