# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmsimang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 10:48:52 by bmsimang          #+#    #+#              #
#    Updated: 2018/08/14 10:49:06 by bmsimang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bmsimang

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBS = libft/libft.a

INCLUDES = filler.h

SRC = initialise_game.c prepare_move.c make_move.c lst_stuff.c main.c

all: $(NAME)

$(NAME):
	$(MAKE) -C libft/ all
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LIBS)

clean:
	$(MAKE) -C libft/ fclean

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all
	$(MAKE) - C libft fclean re
