NAME = push_swap

BONUS_NAME = checker

CC = cc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lm -lft -L$(LIBFT_DIRECTORY) 
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

HEADER = push_swap.h
HEADERS_DIRECTORY = .

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)


SOURCES = main.c init_stack.c index.c sort_1.c sort3.c max_sort_seq.c add_cmd.c push_to_b.c rotations.c push.c swap.c rotate.c ft_error.c fill_stack_a.c ft_atol.c
SOURCES_BONUS = checker_main.c get_next_line.c get_next_line_utils.c  init_stack.c  push.c swap.c rotate.c ft_error.c fill_stack_a.c ft_atol.c add_cmd.c

OBJECTS	=  $(SOURCES:%.c=%.o)
OBJECTS_BONUS = $(SOURCES_BONUS:%.c=%.o) 

GREEN = \033[0;32m
RED = \033[0;31m
CROSS = \033[9m
MARK = \033[7m
RESET = \033[0m

.PHONY: all clean fclean re bonus

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(MARK) $(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(MARK) $(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(BONUS_NAME): $(LIBFT) $(OBJECTS_BONUS)
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS_BONUS) -o $(BONUS_NAME)
	@echo "\n $(MARK) $(BONUS_NAME): $(GREEN)object files were created$(RESET)"
	@echo " $(MARK) $(BONUS_NAME): $(GREEN)$(BONUS_NAME) was created$(RESET)"

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIRECTORY)/*.c $(LIBFT_DIRECTORY)/*.h
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS) $(OBJECTS_BONUS)
	@echo " $(NAME): $(RED) $(CROSS)object $(RED) files were deleted$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean
	@echo " $(CROSS)$(LIBFT): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo "$(CROSS) $(NAME) $(BONUS_NAME): $(RED)$(NAME) and $(BONUS_NAME) was deleted$(RESET)"

re: fclean all