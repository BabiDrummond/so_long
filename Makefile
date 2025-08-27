NAME = solong.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = map_validator.c
OBJ = $(SRC:.c=.o)
MINILIBX = minilibx-linux
MFLAGS = 
LIB_SRC = libft

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	fclean all