# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chourael <chourael@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 17:54:13 by chchour           #+#    #+#              #
#    Updated: 2023/12/28 17:13:16 by chourael         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec

CC = cc

SRCS = exec-main.c lastcmd.c firstcmd.c middlecmd.c 1cmd.c make-close_pipes.c

OBJS = $(SRCS:.c=.o)

LIB_DIR = ../Marianne_libft

LIB_NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -g

LFLAGS = -lreadline

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/$(LIB_NAME) -o $(NAME) $(LFLAGS)

clean:
	make clean -C $(LIB_DIR)
	rm -rf $(OBJS)

fclean:
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME) $(OBJS)

re: fclean
	make all

.PHONY: all clean fclean re