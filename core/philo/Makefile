NAME		:= philo

INC_DIR		:= ./includes/
INCLUDES	:= -I $(INC_DIR)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g -pthread 

RM			:= rm -rf

SRC_DIR		:= ./src
SRC_FILES	:= philo.c error_handle.c
SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR	:= ./build
OBJ_FILES	:= philo.o error_handle.o			
OBJ			:= $(addprefix $(BUILD_DIR)/, $(OBJ_FILES)) 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(INCLUDES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY: all clean fclean re

clean:
	$(RM) $(BUILD_DIR)/
	@echo "clean"

fclean: clean
	$(RM) $(NAME)
	@echo "fclean"

re: fclean all
