# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 14:33:27 by jroulet           #+#    #+#              #
#    Updated: 2024/02/02 14:33:28 by jroulet          ###   ########.fr        #
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
		${CC} ${CFLAGS} -Iutils -c $? -o $@

${NAME}:	 server client

git: fclean
	git add .
	git commit -m "$t" -m"$b"
	git push

server:		server.o
		@make -C utils
		${CC} ${CFLAGS} $? -Lutils -lft -o server

client:		client.o
		@make -C utils
		${CC} ${CFLAGS} $? -Lutils -lft -o client

libft:
		make -C utils

clean:
			make clean -C utils
			${RM} ${OBJS}

fclean:		clean
			${RM} server client

re:			fclean all

.PHONY:		printf