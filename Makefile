cflags = -Wall -Werror -Wextra

rm = rm -rf

frameworks = -framework CoreFoundation -framework AppKit -framework OpenGl

NAME = so_long

src = libft/ft_*.c main.c ./map/*.c ./data_structures/*.c game/*.c

all: $(NAME)

$(NAME) : $(src) so_long.h
			$(MAKE) -C libft/
			$(CC) -lz -lmlx $(frameworks) $(src) $(mlx_src) -o $(NAME)

clean:
	$(MAKE) clean -C libft/

fclean: clean
	$(MAKE) fclean -C libft/
	$(rm) $(NAME)

re: fclean all

.PHONY: all clean fclean re