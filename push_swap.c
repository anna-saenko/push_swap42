#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		check_args(argc, argv);
		args = prepare_args(argc, argv);
		printf("Args: %p\n", args);
		stack_a = parse_args_to_linked_list(args);
		if (is_sorted(stack_a))
		{
			printf("Stack is sorted\n");
		}
		else
		{
			printf("Stack is not sorted\n");
		}
		printf("Stack_a: %p\n", stack_a);
		print_stack(stack_a);
		free_stack(stack_a);
	}
	return (0);
}