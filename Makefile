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
UTILSNAME = libft.a

all: makeutils $(CLIENT) $(SERVER)

makeutils:
	make -C $(UTILSDIR)
	cp $(UTILSDIR)/$(UTILSNAME) .
	mv $(UTILSNAME) $(UTILSDIR)

$(CLIENT): client.c
	$(CC) $(FLAGS) client.c -L$(UTILSDIR) -lft -o $(CLIENT)

$(SERVER): server.c
	$(CC) $(FLAGS) server.c -L$(UTILSDIR) -lft -o $(SERVER)

bonus: makeutils $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): client_bonus.c
	$(CC) $(FLAGS) client_bonus.c -L$(UTILSDIR) -lft -o $(CLIENT_BONUS)

$(SERVER_BONUS): server_bonus.c
	$(CC) $(FLAGS) server_bonus.c -L$(UTILSDIR) -lft -o $(SERVER_BONUS)

git: fclean
	git add .
	git commit -m "$t" -m"$b"
	git push

clean:
	make -C $(UTILSDIR) clean
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	make -C $(UTILSDIR) fclean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus
