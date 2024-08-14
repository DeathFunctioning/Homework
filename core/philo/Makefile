NAME		:= philo

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g -pthread -I$(INC_DIR)/$(INC)

INC			:= philo.h
INC_DIR		:= ./includes

RM			:= rm -rf

SRC_DIR		:= ./src
SRC_FILES	:= philo.c
SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR	:= ./build
OBJ_FILES	:= %.o			
OBJ			:= $(addprefix $(BUILD_DIR)/, $(OBJ_FILES)) 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	$(RM) $(BUILD_DIR)
	@echo "clean"

fclean: clean
	$(RM) $(NAME)
	@echo "fclean"

re: fclean all
