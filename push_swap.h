#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				index;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
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

char	**parse_args(int argc, char **argv);

#endif