NAME		:= megaphone

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -g -std=c++98

RM			:= rm -rf

SRC_FILES	:= megaphone.cpp

OBJ_FILES	:= $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXPFLAGS) $(OBJ_FILES) -o $@

$(OBJ_FILES): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES)
	@echo "clean"

fclean: clean
	$(RM) $(NAME)
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean
