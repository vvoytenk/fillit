# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osapon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 12:52:53 by osapon            #+#    #+#              #
#    Updated: 2017/12/05 18:42:34 by vvoytenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c memory.c map.c backtracking.c validation.c

LIB = libft.a

OBJ = $(SRC:.c=.o)

FLG = -Wall -Wextra -Werror

all:    $(NAME)

$(NAME): $(LIB) $(OBJ)
	    gcc $(FLG) $(OBJ) -o $(NAME) libft/$(LIB)

%.o: %.c
	gcc $(FLG) -c -o $@ $<

$(LIB):
		make -C ./libft

clean: 
		/bin/rm -f $(OBJ)
		make -C ./libft clean

fclean: clean 
		/bin/rm -f $(NAME)
		make -C ./libft fclean

re: fclean all
