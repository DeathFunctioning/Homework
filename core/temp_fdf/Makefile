NAME		= fdf

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf
INCLUDES	= -Iincludes -I$(MLX_DIR) -I$(LIB_DIR)includes/

SRC_DIR		= src/
SRC_FILES	= main.c init.c matrix.c test_remove.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

MLX_DIR		= mlx_linux/
MLX			= $(MLX_DIR)libmlx_Linux.a 
MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

OBJ_DIR		= objs/
OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

LIB_DIR		= libft/
LIBFT		= $(LIB_DIR)libft.a
LIBFT_FLAGS	= -L$(LIB_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS) mlx libft
	@echo "run it"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

libft:
	@make -C $(LIB_DIR)

mlx:
	@make -C $(MLX_DIR)

clean:
	@echo "clean"
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "fclean"
	@$(RM) $(NAME) $(LIBFT) $(MLX)

re: fclean all

.PHONY: all clean fclean re libft mlx
