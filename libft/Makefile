# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaenko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 14:37:59 by asaenko           #+#    #+#              #
#    Updated: 2024/02/26 14:39:11 by asaenko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

PRINTFDIR = ./ft_printf

PRINTF = libftprintf.a

SRCS = ft_atoi.c	ft_bzero.c	ft_calloc.c	ft_isalnum.c \
		ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c \
		ft_itoa.c	ft_memchr.c	ft_memcmp.c \
		ft_memcpy.c	ft_memmove.c	ft_memset.c	ft_putchar_fd.c \
		ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c \
		ft_strchr.c	ft_strdup.c	ft_striteri.c	ft_strjoin.c \
		ft_strlcat.c	ft_strlcpy.c	ft_strlen.c	ft_strmapi.c \
		ft_strncmp.c	ft_strnstr.c	ft_strrchr.c	ft_strtrim.c \
		ft_substr.c	ft_tolower.c	ft_toupper.c

OBJ = $(SRCS:.c=.o)

all: makeprintf $(NAME)

makeprintf:
	make -C $(PRINTFDIR)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(PRINTFDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTFDIR) fclean

re: fclean all

.PHONY: all clean fclean re

