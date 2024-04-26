#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current = stack;

	while (current != NULL)
	{
		printf("[%02d]: %d -> ", current->index, current->value);
		current = current->next;
	}
	printf("\n");
}