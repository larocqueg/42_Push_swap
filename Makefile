# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 14:20:05 by gde-la-r          #+#    #+#              #
#    Updated: 2024/12/27 11:02:54 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the returning file
NAME = push_swap

# Compilation method and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Macros for each folder
INCLUDES = ./includes
SRC_DIR = ./sources
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft-printf

# Files to search at each folder
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/rules.c \
      $(SRC_DIR)/errors.c
OBJ = $(SRC:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# After compiling everything it returns a file with the NAME
all: $(NAME)

# Compiles the OBJ and LIBFT to the NAME
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJ) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -o $(NAME)

# Runs make for LIBFT
$(LIBFT):
	make -C $(LIBFT_DIR)

# Runs make for FT_PRINTF
$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

# Removes all .o files
clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

# Run clean and remove the NAME and LIBFT_NAME
fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

# Run fclean followed by all
re: fclean all

# Avoid name clashes
.PHONY: all clean fclean re
