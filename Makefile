# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 18:37:45 by jroulet           #+#    #+#              #
#    Updated: 2024/01/22 15:49:56 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c

OBJS	:= $(SRCS:%.c=%.o)

NAME	= minitalk

CC		= gcc
RM		= rm -f

CFLAGS 	= -g -Wall -Wextra -Werror

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -c $? -o $@

${NAME}:	 server client

git: fclean
	git add .
	git commit -m "$t" -m"$b"
	git push

server:		server.o
		@make -C libft
		${CC} ${CFLAGS} $? -Llibft -lft -o server

client:		client.o
		@make -C libft
		${CC} ${CFLAGS} $? -Llibft -lft -o client

libft:
		make -C libft

clean:
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			${RM} server client

re:			fclean all

.PHONY:		libft printf
