#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

char	**prepare_args(int argc, char **argv);
//check_args.c
void	check_args(int argc, char **argv);

t_stack	*parse_args_to_linked_list(char **args);
//free_funcs.c
void	free_char_arr(char **arr);
void	free_stack(t_stack *stack);
//utils.c
void	print_stack(t_stack *stack);

#endif