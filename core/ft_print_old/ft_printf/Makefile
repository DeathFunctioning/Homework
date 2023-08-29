# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbaker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 18:32:17 by tbaker            #+#    #+#              #
#    Updated: 2023/08/02 19:01:03 by tbaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printf.c

OBJS = ${SRCS:.c=.o}

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Time to printf................."
	@echo "....Its just beautiful dream/disaster....."
	@echo "Also no bonus!"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
