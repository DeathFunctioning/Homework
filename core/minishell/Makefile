NAME		:= minishell

INC_DIR		:= ./include/
INCLUDE		:= -I $(INC_DIR) 

C			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g

RM			:= rm -rf

SRC_DIR		:= ./src
SRC_FILES	:= main.c
SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR	:= ./build
OBJ_FILES	:= $(SRC_FILES:.c=.o)
OBJ			:= $(addprefix $(BUILD_DIR)/, $(OBJ_FILES)) 

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(CFLAGS) $(OBJ) -o $@ $(INCLUDE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(BUILD_DIR)
	$(C) $(CFLAGS) -c $< -o $@ $(INCLUDE)

.PHONY: all clean fclean re

clean:
	$(RM) $(BUILD_DIR)/
	@echo "clean"

fclean: clean
	$(RM) $(NAME)
	@echo "fclean"

re: fclean all
