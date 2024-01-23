# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 14:55:40 by crmanzan          #+#    #+#              #
#    Updated: 2024/01/23 13:13:48 by crmanzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

SRCS = 	ft_isalnum.c \
		ft_split.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strlen.c \
		ft_memset.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_atoi.c \
		ft_itoa.c \
 		ft_calloc.c \
		ft_bzero.c \
		ft_strtrim.c \
		ft_strlcpy.c \
		ft_strjoin.c \
		ft_strnstr.c \
		ft_memcmp.c \
		ft_strrchr.c \
		ft_strchr.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strlcat.c \
		ft_strncmp.c \
		ft_memcpy.c \
		ft_printf.c \
		ft_char_printf.c \
		ft_str_printf.c \
		ft_hexptr_printf.c \
		ft_nbr_printf.c \
		ft_unnbr_printf.c

OBJ = $(SRCS:.c=.o)
DEP = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

-include $(DEP)

%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re
