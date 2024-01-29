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

CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

LIBFT_MAKE=make -s -C libft/
LIBFT=libft/libft.a

SRCS = 	server.c
SRCC = 	client.c


OBJ_S = $(SRCS:.c=.o)
OBJ_C = $(SRCC:.c=.o)
DEP_S = $(SRCS:.c=.d)
DEP_C = $(SRCC:.c=.d)

all: $(CLIENT) $(SERVER) 

$(SERVER): libft $(OBJ_S)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ_S) -o $@

$(CLIENT): libft $(OBJ_C)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ_C) -o $@

-include $(DEP_S) $(DEP_C)

%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(LIBFT_MAKE)

clean:
	$(LIBFT_MAKE) clean
	rm -rf $(OBJ_C) $(DEP_C) $(OBJ_S) $(DEP_S)

fclean: clean
	$(LIBFT_MAKE) fclean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all
.PHONY: all libft clean fclean re
