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
MAIN = ./sources/main.c  # Explicitly define main.c for push_swap

# Objects, libft, and ft_printf inclusion
OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)
MAIN_OBJ = $(MAIN:.c=.o)  # Object for main.c
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Default rule (build push_swap)
all: $(NAME_PUSH_SWAP)

# Build push_swap executable (with main.o)
$(NAME_PUSH_SWAP): $(OBJ) $(MAIN_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -I $(INCLUDES) $(OBJ) $(MAIN_OBJ) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -o $(NAME_PUSH_SWAP)

# Build bonus executable (using bonus.o and bonus.c)
bonus: $(OBJ) $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -I $(INCLUDES) -I ./bonus $(OBJ) $(BONUS_OBJ) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -o $(NAME_BONUS)

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build ft_printf
$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

# Compile object files for main, bonus, and other sources
%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -I ./bonus -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJ) $(BONUS_OBJ) $(MAIN_OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

# Full clean
fclean: clean
	rm -rf $(NAME_PUSH_SWAP) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

# Rebuild everything
re: fclean all

# Avoid name clashes
.PHONY: all clean fclean re bonus
