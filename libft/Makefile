# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 18:14:43 by fsinestr          #+#    #+#              #
#    Updated: 2022/01/05 21:29:28 by fsinestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cflags	= -Wall -Wextra -Werror

rm		= rm -rf

name 	= libft.a

header 	= libft.h

srcm 	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c ft_isupper.c ft_tolower.c ft_toupper.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memchr.c \
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strcmp.c ft_strnstr.c \
			ft_strdup.c ft_strndup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_atoi.c ft_strtol.c ft_itoa.c ft_calloc.c

objm	= $(srcm:.c=.o)

srcb	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c

objb	= $(srcb:.c=.o)

all: $(name)

$(name): $(objm)
	ar -crs $(name) $?

$(objm): %.o: %.c $(header)
	$(CC) $(cflags) -c $< -o $@

clean:
	$(rm) *.o

fclean: clean
	$(rm) $(name)

re: fclean all

bonus: $(objb)
	ar -crs $(name) $?

$(objb): %.o: %.c $(header)
	$(CC) $(cflags) -c $< -o $@

.PHONY: all clean fclean re
