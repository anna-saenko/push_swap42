# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaenko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 15:29:07 by asaenko           #+#    #+#              #
#    Updated: 2024/06/06 10:30:27 by asaenko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFTDIR = libft

LIBFTNAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -O0 -DDEBUG

SRCS = push_swap.c	args_check.c free_funcs.c	utils.c \
		args_parse.c	ops_push.c	ops_swap.c	ops_rotate.c \
		ops_reverse.c	sort.c sort_five.c sort_utils.c \
		sort_above_five.c sort_above_five_a_utils.c \
		sort_above_five_b_utils.c

OBJ = $(SRCS:.c=.o)

all: makelibft $(NAME)

makelibft:
	make -C $(LIBFTDIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFTDIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re


