CC			= gcc
CFLAGS 		= -Wall -Werror -Wextra
NAME		= push_swap
INCS		= -I ./includes/

SRC_PATH	= src/
OBJ_PATH	= obj/

SRC			= push_swap.c \
			  init.c \
			  utils.c \
			  rotate_stack.c \
			  reverse_rotate_stack.c \
			  swap_stack.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all:	$(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

# make run ARGS="arg1 arg2" 
run: all
	@./$(NAME) $(ARGS)
	@echo Exit code:$$?

.PHONY: all clean fclean re
