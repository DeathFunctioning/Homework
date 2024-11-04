NAME		:= job

INC_DIR		:= ./include/
INCLUDE		:= -I $(INC_DIR)

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -g -std=c++98

RM			:= rm -rf

SRC_DIR		:= ./src
SRC_FILES	:= test.cpp Account.cpp
SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR	:= ./build
OBJ_FILES	:= $(SRC_FILES:.cpp=.o)
OBJ			:= $(addprefix $(BUILD_DIR)/, $(OBJ_FILES)) 

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(INCLUDE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)%.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

.PHONY: all clean fclean re

clean:
	$(RM) $(BUILD_DIR)/
	@echo "clean"

fclean: clean
	$(RM) $(NAME)
	@echo "fclean"

re: fclean all
