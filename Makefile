NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include/

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx
MLX_FLAGS = -L$(MLX_DIR) -lXext -lX11 -lpthread

SRCS_DIR = src/
SRCS = validation/file_validator.c 	\
	validation/flood_fill.c 		\
	validation/map_validator.c 		\
	error_handler.c					\
	map_loader.c
OBJS_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo -n "\033[0;32mGenerated so_long\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[95mCompiling $(notdir $<)"

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	@echo "\033[0;34mCleaning so_long objects"
	@rm -rf $(OBJS_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[0;34mCleaning so_long"
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

run: re
	./$(NAME)

gdb: CFLAGS += -g -O0
gdb: re
	@gdb ./$(NAME)

valgrind: re
	valgrind ./$(NAME)
	
.PHONY: $(LIBFT) clean fclean re