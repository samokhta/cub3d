NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

SRC = src/check_file.c src/check_file2.c src/draw.c src/draw2.c src/fdf.c src/fdf2.c src/hooks.c src/parsing.c src/parsing2.c src/utils.c

OBJ = src/check_file.o src/check_file2.o src/draw.o src/draw2.o src/fdf.o src/fdf2.o src/hooks.o src/parsing.o src/parsing2.o src/utils.o

HEADERS = fdf.h mlx.h libft.h

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(LIBFT_DIR) $(MLX_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -s -C $(MLX_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(LIBFT) $(BONUS_OBJ) $(BONUS_HEADERS)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(LIBFT_DIR)/*.o
	rm -f $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f result.txt

re: fclean all