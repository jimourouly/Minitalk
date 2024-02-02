# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 20:02:41 by jroulet           #+#    #+#              #
#    Updated: 2023/11/25 17:19:58 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = 	ft_print_char.c\
		ft_print_hex.c\
		ft_print_nbr.c\
		ft_print_percent.c\
		ft_print_ptr.c\
		ft_print_str.c\
		ft_print_uns.c\
		ft_printf.c\
		ft_uitoa.c\
		ft_putchar_fd.c\
		ft_itoa.c\
		ft_atoi.c\


OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all
