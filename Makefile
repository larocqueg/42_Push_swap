# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 15:35:43 by gde-la-r          #+#    #+#              #
#    Updated: 2025/01/25 15:35:43 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executables
NAME_PUSH_SWAP = push_swap
NAME_BONUS = checker

# Compilation method and flags
CC = cc
FLAGS = -Wall -Wextra -Werror -g

# Directories
COMMANDS_DIR = ./sources/commands
PW_DIR = ./sources
INCLUDES = ./includes
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf

# Source files
SRCS = $(COMMANDS_DIR)/swap.c \
       $(COMMANDS_DIR)/push.c \
       $(COMMANDS_DIR)/rev_rotate.c \
       $(COMMANDS_DIR)/rotate.c \
       $(PW_DIR)/utils.c \
       $(PW_DIR)/sort.c \
       $(PW_DIR)/sort_utils.c \
       $(PW_DIR)/error.c \
       $(PW_DIR)/init_stack.c \
       $(PW_DIR)/free.c \
       $(PW_DIR)/sort_utils_utils.c

BONUS = ./bonus/bonus.c
MAIN = ./sources/main.c

# Objects, libft, and ft_printf inclusion
OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)
MAIN_OBJ = $(MAIN:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME_PUSH_SWAP)

$(NAME_PUSH_SWAP): $(OBJ) $(MAIN_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -I $(INCLUDES) $(OBJ) $(MAIN_OBJ) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -o $(NAME_PUSH_SWAP)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ) $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -I $(INCLUDES) -I ./bonus $(OBJ) $(BONUS_OBJ) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -o $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -I ./bonus -c $< -o $@

clean:
	rm -rf $(OBJ) $(BONUS_OBJ) $(MAIN_OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -rf $(NAME_PUSH_SWAP) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean
	make all
	make bonus

.PHONY: all clean fclean re bonus
