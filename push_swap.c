#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = check_args(argc, argv);
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	return (0);
}