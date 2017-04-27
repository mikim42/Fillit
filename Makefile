# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 16:44:18 by mikim             #+#    #+#              #
#    Updated: 2017/03/22 04:45:28 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c		\
	  ft_fill.c		\
	  ft_create.c	\
	  ft_check.c	\
	  ft_valid.c	\
	  ft_print.c	\
	  ft_tools.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.PHONY: $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(FLAGS) $(SRC)
	gcc $(OBJ) -o $(NAME)

%.o: %.c
	gcc -c $(FLAGS) $(SRC) $^ $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
