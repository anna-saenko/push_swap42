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

typedef struct s_all
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		min_a;
	int		median;
	int		len_a;
	int		len_b;
}	t_all;

char	**prepare_args(int argc, char **argv);
void	check_args(int argc, char **argv);

#endif