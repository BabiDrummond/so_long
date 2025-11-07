NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iinclude/

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_DEPENCENCIES = -lXext -lX11 -lm -lz -lpthread

SRCS_DIR = src/
SRCS = graphics/get_rgb.c			\
	graphics/destroy_sprites.c		\
	graphics/render_sprites.c		\
	graphics/load_sprites.c			\
	gameplay/check_exit.c			\
	gameplay/close_game.c			\
	gameplay/key_press.c			\
	gameplay/move_player.c			\
	parsing/map_init_values.c 		\
	parsing/map_init_positions.c 	\
	parsing/map_load.c 				\
	parsing/map_parse.c				\
	parsing/map_read.c				\
	validation/error_handler.c		\
	validation/validate_chars.c 	\
	validation/validate_elements.c 	\
	validation/validate_filename.c 	\
	validation/validate_path.c 		\
	validation/validate_size.c 		\
	validation/validate_walls.c 	\
	main.c
OBJS_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(MLX) $(MLX_DEPENCENCIES) -o $(NAME)
	@echo -n "\033[0;32mGenerated so_long\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[95mCompiling $(notdir $<)"

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

$(MLX):
	@make --no-print-directory -C $(MLX_DIR)

clean:
	@echo "\033[0;34mCleaning so_long objects"
	@rm -rf $(OBJS_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@make --no-print-directory -C $(MLX_DIR) clean

fclean: clean
	@echo "\033[0;34mCleaning so_long"
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

run: re
	./$(NAME) maps/map04.ber

gdb: CFLAGS += -g -O0
gdb: re
	@gdb ./$(NAME) maps/map03.ber

valgrind: re
	valgrind ./$(NAME) maps/map04.ber
	
.PHONY: $(LIBFT) clean fclean re