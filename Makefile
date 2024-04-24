NAME = push_swap

LIBFTDIR = libft

LIBFTNAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c	check_args.c \

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


