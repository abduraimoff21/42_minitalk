# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 10:19:03 by dabdurai          #+#    #+#              #
#    Updated: 2023/01/24 20:06:04 by dabdurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.c
SERVER = server.c
CLIENT_NAME = client
SERVER_NAME = server

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT)
	$(CC) $(FLAGS) utils.c $(CLIENT) -o $(CLIENT_NAME)
	
$(SERVER_NAME) : $(SERVER)
	$(CC) $(FLAGS) utils.c $(SERVER) -o $(SERVER_NAME)
	
clean :
	$(RM) server.o client.o

norme :
	norminette

fclean :
	$(RM) server client
	
re : fclean all
.PHONY: all clean fclean re