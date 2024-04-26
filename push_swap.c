#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;

	check_args(argc, argv);
	args = prepare_args(argc, argv);
	printf("Args: %p\n", args);
	stack_a = parse_args_to_linked_list(args);
	printf("Stack_a: %p\n", stack_a);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}