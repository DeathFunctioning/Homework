NAME		= fdf

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf
INCLUDES	= -I includes/

# linux

MLX_DIR		= mlx_linux/
MLX			= $(MLX_DIR)/libmlx_Linux.a 
MLX_FLAGS	= -Lmlx_linux -Lmlx_Linux -L/usr/lib -1Xext -1X11 -1m -1z

SRC_DIR		= src/
SRC_FILES	= main.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		= obj/
OBJ			= 

LIB_DIR		= libft/
LIBFT		= $(LIB_DIR)/libft.a














all: $(NAME)

$(NAME): $(OBJS)

clean:

fclean: clean
	$(RM) $(OBJ_DIR)

re: fclean all
