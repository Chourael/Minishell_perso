# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chourael <chourael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:13:51 by chourael          #+#    #+#              #
#    Updated: 2023/12/12 13:51:49 by chourael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MOAT

CC = cc

SRCS = MOAT.c ft_mega_split.c libstuff.c

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