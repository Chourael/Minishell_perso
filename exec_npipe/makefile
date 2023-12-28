# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chourael <chourael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 17:54:13 by chchour           #+#    #+#              #
#    Updated: 2023/12/28 15:58:25 by chourael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec

CC = cc

SRCS = exec-main.c lastcmd.c firstcmd.c middlecmd.c malloc-close_pipes.c

OBJS = $(SRCS:.c=.o)

LIB_DIR = ../Marianne_Libft

LIB_NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -g

LFLAGS = -lreadline

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBP_DIR)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

clean:
	make clean -C $(LIB_DIR)
	make clean -C $(LIBP_DIR)
	rm -rf $(OBJS)

fclean:
	make fclean -C $(LIB_DIR)
	make fclean -C $(LIBP_DIR)
	rm -rf $(NAME) $(OBJS)

re: fclean
	make all

.PHONY: all clean fclean re