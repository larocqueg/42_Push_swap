# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 14:20:05 by gde-la-r          #+#    #+#              #
#    Updated: 2024/12/16 16:18:48 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap.a

CC=cc

CFLAGS= -Wall -Wextra -Werror

INCLUDES=./includes/push_swap.h

SRC_DIR=./sources

SRC= $(SRC_DIR)/main.c \
	 $(SRC_DIR)/rules.c \
	 $(SRC_DIR)/errors.c \

OBJ= $(SRC: .c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES)
