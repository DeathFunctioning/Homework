# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbaker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 18:32:17 by tbaker            #+#    #+#              #
#    Updated: 2023/08/06 21:55:35 by tbaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = ft_printf.c
SRCS = $(addsuffix .c, $(SRC))

OBJ_DIR = OBJ
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "Time to printf................."
	@echo "....Its just beautiful dream/disaster....."
	@echo "Also no bonus!"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean: clean
		make -C $(LIBFT_PATH) fclean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
