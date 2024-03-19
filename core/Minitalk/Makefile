CC				= gcc
CFLAGS 			= -Wall -Werror -Wextra 

CLIENT			= client
SERVER			= server

LIBFT_DIR 		= $(SRC_DIR)/libft
FT_PRINTF_DIR 	= $(SRC_DIR)/ft_printf
SRC_DIR			= src
OBJ_DIR			= objs

INCS			= -I./includes -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

SRCS			= $(SRC_DIR)/client.c $(SRC_DIR)/server.c 

OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OB_DIR)/%.o)


all:	$(OBJ_DIR) libft ft_printf $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_DIR)/client.o
	@$(CC) $(CFLAGS) $(INCS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf 

$(SERVER): $(OBJ_DIR)/server.o
	@$(CC) $(CFLAGS) $(INCS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -rf $(CLIENT) $(SERVER)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all libft ft_printf clean fclean re
