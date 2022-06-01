# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbulut <fbulut@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 14:00:20 by fbulut            #+#    #+#              #
#    Updated: 2022/05/25 14:00:21 by fbulut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
printf= src/libftprintf.a

CLİENT = client
SERVER = server

all: $(SERVER) $(CLİENT)

$(SERVER):
	make -C ./src
	$(CC) $(CFLAGS) server.c utils.c $(printf) -o $@

$(CLİENT):
	make -C ./src
	$(CC) $(CFLAGS) client.c utils.c $(printf) -o $@

clean:
	make fclean -C ./src
	rm server client


fclean: clean

re: fclean all

.PHONY: all clean fclean coffee re