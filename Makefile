# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 14:20:05 by gde-la-r          #+#    #+#              #
#    Updated: 2024/12/17 13:41:44 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CC=cc
CFLAGS= -Wall -Wextra -Werror

INCLUDES=./includes
SRC_DIR=./sources
SRC= $(SRC_DIR)/main.c \
	 $(SRC_DIR)/rules.c \
	 $(SRC_DIR)/errors.c 
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make

.PHONY: all clean fclean re
