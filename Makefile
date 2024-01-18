# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 14:55:40 by crmanzan          #+#    #+#              #
#    Updated: 2024/01/18 19:15:22 by crmanzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

SRCS = 	

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
