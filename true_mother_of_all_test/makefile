# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chchour <chchour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 17:54:13 by chchour           #+#    #+#              #
#    Updated: 2023/12/21 14:08:36 by chchour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = True_MOAT

CC = cc

SRCS = main.c libstuff.c cmds.c ft_mega_split.c help.c paths.c init.c fullcmd.c

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