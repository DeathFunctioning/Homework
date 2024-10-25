NAME		:= phonebook

INC_DIR		:= ./includes/
INCLUDES	:= -I $(INC_DIR)*.h $(INC_DIR)*.hpp

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -g =std=c++98

RM			:= rm -rf

SRC_DIR		:= ./src
SRC_FILES	:= PhoneBook.cpp 
SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR	:= ./build
OBJ_FILES	:= philo.o error_handle.o utils.o init.o create_threads.o \
			   philo_actions.o
OBJ			:= $(addprefix $(BUILD_DIR)/, $(OBJ_FILES)) 

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(INCLUDES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)*.h
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY: all clean fclean re

clean:
	$(RM) $(BUILD_DIR)/
	@echo "clean"

fclean: clean
	$(RM) $(NAME)
	@echo "fclean"

re: fclean all
