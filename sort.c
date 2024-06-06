#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 3)
	{
		sort_three(stack_a, size);
		return ;
	}
	else if (size <= 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	else
	{
		sort_above_five_elements(stack_a, stack_b);
	}
	stack_b = NULL;
}

void	sort_three(t_stack **stack_a, int size)
{
	if (is_sorted(*stack_a))
		return ;
	if (size == 2)
	{
		sa(stack_a);
	}
	else if (size == 3)
	{
		if ((*stack_a)->next->next->value > (*stack_a)->value && (*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a);
		}
		else if ((*stack_a)->value > (*stack_a)->next->value)
		{
			ra(stack_a);
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
		}
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			rra(stack_a);
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
		}
	}
}
