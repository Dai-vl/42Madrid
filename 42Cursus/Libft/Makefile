# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 21:11:33 by dvidal-l          #+#    #+#              #
#    Updated: 2023/09/20 18:23:33 by dvidal-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BASIC_SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c

NAME = libft.a
BASIC_OBJ = $(BASIC_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_TARGET = .bonus_aux

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(BASIC_OBJ)
	ar -rcs $(NAME) $(BASIC_OBJ)

bonus: $(BONUS_TARGET)

$(BONUS_TARGET): $(NAME) $(BONUS_OBJ) $(BASIC_OBJ)
	ar -rcs $(NAME) $(BONUS_OBJ) $(BASIC_OBJ)
	touch $(BONUS_TARGET)

re: fclean all

rebonus: fclean bonus

clean:
	rm -f $(BASIC_OBJ) $(BONUS_OBJ) $(BONUS_TARGET)

fclean: clean
	rm -f $(NAME)

.PHONY: fclean all clean re bonus rebonus