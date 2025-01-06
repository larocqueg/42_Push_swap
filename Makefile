# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 13:56:33 by gde-la-r          #+#    #+#              #
#    Updated: 2025/01/06 11:36:28 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = push_swap

# Compilation method and flags
CC = cc
FLAGS = -Wall -Wextra -Werror

# Directories
COMMANDS_DIR = ./sources/commands
PW_DIR = ./sources
INCLUDES = ./includes
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf

# Source files
SRCS = $(COMMANDS_DIR)/push.c \
       $(COMMANDS_DIR)/rev_rotate.c \
       $(COMMANDS_DIR)/rotate.c \
       $(COMMANDS_DIR)/sort_stacks.c \
       $(COMMANDS_DIR)/sort_three.c \
       $(COMMANDS_DIR)/swap.c \
       $(PW_DIR)/main.c \
	   $(PW_DIR)/utils.c \
	   $(PW_DIR)/sort.c \
	   $(PW_DIR)/error.c

# Objects, libft, and ft_printf inclusion
OBJ = $(SRCS:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Default rule
all: $(NAME)

# Build the executable
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -I $(INCLUDES) $(OBJ) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -o $(NAME)

# Build libft
$(LIBFT):
	make bonus -C $(LIBFT_DIR)

# Build ft_printf
$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

# Compile object files
%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

# Full clean
fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

# Rebuild everything
re: fclean all

# Avoid name clashes
.PHONY: all clean fclean re
