#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **args;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	args = parse_args(argc, argv);
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", args[i]);
	}
	return (0);
}