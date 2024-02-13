# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crmanzan <crmanzan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 14:55:40 by crmanzan          #+#    #+#              #
#    Updated: 2024/02/13 19:50:02 by crmanzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

LIBFT_MAKE=make -s -C libft/
LIBFT=libft/libft.a

SRCS = 	server.c
SRCC = 	client.c
SRCS_BONUS = 	server_bonus.c
SRCC_BONUS = 	client_bonus.c


OBJ_S = $(SRCS:.c=.o)
OBJ_C = $(SRCC:.c=.o)
OBJ_S_BONUS = $(SRCS_BONUS:.c=.o)
OBJ_C_BONUS = $(SRCC_BONUS:.c=.o)
DEP_S = $(SRCS:.c=.d)
DEP_C = $(SRCC:.c=.d)
DEP_S_BONUS = $(SRCS_BONUS:.c=.d)
DEP_C_BONUS = $(SRCC_BONUS:.c=.d)

all: $(CLIENT) $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(SERVER): libft $(OBJ_S)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ_S) -o $@

$(CLIENT): libft $(OBJ_C)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ_C) -o $@
	
#BONUS 
$(SERVER_BONUS): libft $(OBJ_S_BONUS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ_S_BONUS) -o $@

$(CLIENT_BONUS): libft $(OBJ_C_BONUS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ_C_BONUS) -o $@

-include $(DEP_S) $(DEP_C) $(DEP_C_BONUS) $(DEP_S_BONUS)
#BONUS

%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(LIBFT_MAKE)

clean:
	$(LIBFT_MAKE) clean
	rm -rf $(OBJ_C) $(DEP_C) $(OBJ_S) $(DEP_S) $(OBJ_C_BONUS) $(DEP_C_BONUS) $(OBJ_S_BONUS) $(DEP_S_BONUS)

fclean: clean
	$(LIBFT_MAKE) fclean
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all
.PHONY: all bonus libft clean fclean re
