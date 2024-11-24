# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 19:38:15 by kokamoto          #+#    #+#              #
#    Updated: 2024/11/24 19:46:13 by kokamoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minitalk.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCDIR = .
LIBDIR = libft

SRC = $(SRCDIR)/client.c server.c
LIB = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIB)
	$(CC) $(CFLAGS) -I $(LIBDIR) -c $(SRC)
	ar rc $(NAME) client.o server.o $(LIBDIR)/*.o

$(LIB):
	make -C $(LIBDIR)

clean:
	rm -f client.o server.o
	make -C $(LIBDIR) fclean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean


re: fclean all
