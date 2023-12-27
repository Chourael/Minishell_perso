# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chchour <chchour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 17:54:13 by chchour           #+#    #+#              #
#    Updated: 2023/12/27 13:03:44 by chchour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

SRCS = main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

LFLAGS = -lreadline

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re: fclean
	make all

.PHONY: all clean fclean re