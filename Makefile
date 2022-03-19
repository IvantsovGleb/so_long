cflags = -Wall -Werror -Wextra

frameworks = -framework CoreFoundation -framework AppKit -framework OpenGl

NAME = so_long

src = libft/ft_*.c main.c error.c ./map/*.c ./data_structures/*.c \
		game/*.c

mlx_src = ./mlx/mlx_new_window.m ./mlx/mlx_init_loop.m ./mlx/mlx_new_image.m \
			./mlx/mlx_shaders.c ./mlx/mlx_int_str_to_wordtab.c ./mlx/mlx_xpm.c \
			./mlx/mlx_mouse.m

#$(CC) -lz $(frameworks) $(src) -o $(NAME)

$(NAME) : $(src) so_long.h
			$(CC) -lz $(frameworks) $(src) $(mlx_src) -o $(NAME)