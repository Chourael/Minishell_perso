# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chourael <chourael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 17:54:13 by chchour           #+#    #+#              #
#    Updated: 2023/12/28 15:09:05 by chourael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec

CC = cc

SRCS = exec-main.c lastcmd.c firstcmd.c middlecmd.c malloc-close_pipes.c

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