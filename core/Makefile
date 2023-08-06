# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbaker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 18:32:17 by tbaker            #+#    #+#              #
#    Updated: 2023/08/06 18:51:46 by tbaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

PRINTFDIR = ./ft_printf
LIBDIR = ./libft
BUILDDIR = ./build 

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(PRINTFDIR) I$(LIBDIR)
RM = rm -f

LIBFT_SRCS = $(LIBDIR)/ft_atoi.c $(LIBDIR)/ft_bzero.c $(LIBDIR)/ft_isalnum.c $(LIBDIR)/ft_isalpha.c $(LIBDIR)/ft_isascii.c $(LIBDIR)/ft_isdigit.c $(LIBDIR)/ft_isprint.c $(LIBDIR)/ft_memchr.c $(LIBDIR)/ft_memcmp.c $(LIBDIR)/ft_memcpy.c $(LIBDIR)/ft_memmove.c $(LIBDIR)/ft_memset.c $(LIBDIR)/ft_strchr.c $(LIBDIR)/ft_strlcat.c $(LIBDIR)/ft_strlen.c $(LIBDIR)/ft_strncmp.c $(LIBDIR)/ft_strnstr.c $(LIBDIR)/ft_strrchr.c $(LIBDIR)/ft_tolower.c $(LIBDIR)/ft_toupper.c $(LIBDIR)/ft_calloc.c $(LIBDIR)/ft_strdup.c $(LIBDIR)/ft_substr.c $(LIBDIR)/ft_strjoin.c $(LIBDIR)/ft_strtrim.c $(LIBDIR)/ft_split.c $(LIBDIR)/ft_itoa.c $(LIBDIR)/ft_strmapi.c $(LIBDIR)/ft_striteri.c $(LIBDIR)/ft_putchar_fd.c $(LIBDIR)/ft_putstr_fd.c $(LIBDIR)/ft_putendl_fd.c $(LIBDIR)/ft_putnbr_fd.c

PRINTF_SRCS = $(PRINTFDIR)/ft_printf.c \

LIBFT_OBJS = $(patsubst $(LIBDIR)/%.c, $(BUILDDIR)/%.o, $(LIBFT_SRCS))
PRINTF_OBJS = $(patsubst $(PRINTFDIR)/%.c, $(BUILDDIR)/%.o, $(PRINTF_SRCS))

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS)
	@ar rcs $@ $^
	@echo "Time to printf................."
	@echo "....Its just beautiful dream/disaster....."
	@echo "Also no bonus!"

$(BUILDDIR)/%.o: $(PRINTFDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(LIBDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILDDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
