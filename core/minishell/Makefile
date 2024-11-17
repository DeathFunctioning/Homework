NAME		:= minishell

INC_DIR		:= include/
INCLUDE		:= -I $(INC_DIR) 

C			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
LDFLAGS		:= -lreadline

RM			:= rm -rf

SRC_DIR		:= src
SRC_FILES	:= main.c
SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR	:= build
OBJ_FILES	:= $(SRC_FILES:.c=.o)
OBJ			:= $(addprefix $(BUILD_DIR)/, $(OBJ_FILES)) 

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(CFLAGS) $(INCLUDE) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(BUILD_DIR)
	$(C) $(CFLAGS) $(INCLUDE)-c $< -o $@ 

clean:
	$(RM) $(BUILD_DIR)/
	@echo "clean"

fclean: clean
	$(RM) $(NAME)
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean re
