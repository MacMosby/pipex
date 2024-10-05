# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcrodenbusch <marcrodenbusch@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 18:47:38 by mrodenbu          #+#    #+#              #
#    Updated: 2024/10/05 19:15:22 by marcrodenbu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

SRC := main.c pipex.c

OBJ := $(SRC:%.c=%.o)

CC := cc

CFLAGS := -Wall -Wextra -Werror -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
