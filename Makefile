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

# Colors
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

# Simulate a loading bar
define loading_bar
	@echo -n "$(BLUE)$(1):$(RESET) "
	@for i in $(shell seq 1 100); do \
		sleep 0.01; \
		printf "\r$(BLUE)$(1): %d%%$(RESET)" $$i; \
	done; \
	echo "$(GREEN)\r$(1): 100% Done!$(RESET)"
endef

define loading_bar_red
	@echo -n "$(RED)$(1):$(RESET) "
	@for i in $(shell seq 1 100); do \
		sleep 0.01; \
		printf "\r$(RED)$(1): %d%%$(RESET)" $$i; \
	done; \
	echo "$(GREEN)\r$(1): 100% Done!$(RESET)"
endef

all: $(NAME_PUSH_SWAP)

$(NAME_PUSH_SWAP): $(OBJ) $(MAIN_OBJ) $(LIBFT) $(FT_PRINTF)
	$(call loading_bar,Building lib)
	@$(CC) $(FLAGS) -I $(INCLUDES) $(OBJ) $(MAIN_OBJ) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -o $(NAME_PUSH_SWAP)
	@echo "$(GREEN)Success: push_swap built!$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ) $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	$(call loading_bar,Building bonus lib)
	@$(CC) $(FLAGS) -I $(INCLUDES) -I ./bonus $(OBJ) $(BONUS_OBJ) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -o $(NAME_BONUS)
	@echo "$(GREEN)Success: checker built!$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR) -s

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCLUDES) -I ./bonus -c $< -o $@
	@echo "$(YELLOW)Compiling $<...$(RESET)"

clean:
	$(call loading_bar_red,Cleaning object files)
	@rm -rf $(OBJ) $(BONUS_OBJ) $(MAIN_OBJ)
	@make clean -C $(LIBFT_DIR) -s
	@make clean -C $(FT_PRINTF_DIR) -s
	@echo "$(GREEN)Object files removed successfully!$(RESET)"

fclean: clean
	$(call loading_bar_red,Cleaning libraries)
	@rm -rf $(NAME_PUSH_SWAP) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR) -s
	@make fclean -C $(FT_PRINTF_DIR) -s
	@echo "$(GREEN)Libraries cleaned successfully!$(RESET)"

re: fclean
	$(call loading_bar,Rebuilding project)
	@$(MAKE) all -s
	@$(MAKE) bonus -s
	@echo "$(GREEN)Rebuild completed successfully!$(RESET)"

.PHONY: all clean fclean re bonus
