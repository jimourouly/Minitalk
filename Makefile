# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 16:55:19 by jroulet           #+#    #+#              #
#    Updated: 2024/02/10 17:41:49 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =  -Wall -Werror -Wextra
CC = cc
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRCS = client.c server.c
BSRCS = client_bonus.c server_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

UTILSDIR = ./utils
UTILSNAME = miniutils.a
NAME = minitalk.a

all: makeutils $(CLIENT) $(SERVER)

$(NAME): makeutils $(OBJS) 
	ar -r $(NAME) $(OBJS)

makeutils:
	make -C $(UTILSDIR)
	cp $(UTILSDIR)/$(UTILSNAME) .
	mv $(UTILSNAME) $(NAME)

$(CLIENT): client.c
	$(CC) $(FLAGS) client.c $(NAME)  -o $(CLIENT)

$(SERVER): server.c
	$(CC) $(FLAGS) server.c $(NAME) -o $(SERVER)

bonus: makeutils $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): client_bonus.c
	$(CC) $(FLAGS) client_bonus.c $(NAME) -o $(CLIENT_BONUS)

$(SERVER_BONUS): server_bonus.c
	$(CC) $(FLAGS) server_bonus.c $(NAME) -o $(SERVER_BONUS)

git: fclean
	git add .
	git commit -m "$t" -m"$b"
	git push

clean:
	make -C $(UTILSDIR) clean
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)
	make -C $(UTILSDIR) fclean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus
