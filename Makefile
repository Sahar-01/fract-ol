NAME = fractol

SRC_DIR = src
LIBFT_DIR = libft
INCLUDE_DIR = inc
MLX_DIR = mlx-linux

LIBFT_A = $(LIBFT_DIR)/libft.a

SRC_FILES = $(SRC_DIR)/main.c \
			$(SRC_DIR)/init_mlx.c \
			$(SRC_DIR)/events.c \
			$(SRC_DIR)/julia.c \
			$(SRC_DIR)/mandelbrot.c \
			$(SRC_DIR)/cantor.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/mouse.c \
			$(SRC_DIR)/keys.c \
			$(SRC_DIR)/fractal_utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/inc -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

.PHONY: all clean fclean re

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(LIBFT_A) $(LDFLAGS) -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
