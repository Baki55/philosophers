# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 16:03:11 by bkhatib           #+#    #+#              #
#    Updated: 2022/11/09 16:04:31 by bkhatib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c monitoring.c parsing.c philosophers.c utils.c
OBJS = $(SRCS:.c=.o)
NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -pthread

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re