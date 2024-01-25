# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 14:55:40 by crmanzan          #+#    #+#              #
#    Updated: 2024/01/23 12:48:01 by crmanzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

LIBFT_MAKE=make -s -C libft/
LIBFT=libft/libft.a

SRCS = 	

OBJ = $(SRCS:.c=.o)
DEP = $(SRCS:.c=.d)

all: $(NAME) 

$(NAME): libft $(OBJ)
	ar rcs $(NAME) $(OBJ) 

-include $(DEP)

%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(LIBFT_MAKE)

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all libft clean fclean re
