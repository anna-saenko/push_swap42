#include "push_swap.h"

void	free_char_arr(char **arr)
{
	unsigned	i;

	if (arr == NULL)
		return;
	i = 0;
	while(arr[i] != NULL)
	{
		free(arr[i++]);
	}
	free(arr);
	arr = NULL;
}

void	free_stack(t_stack *stack)
{
	t_stack	*current = stack;

	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	stack = NULL;
}