#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if (stack_size(*stack_a) <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	stack_b = NULL;
}

void	sort_three(t_stack **stack_a)
{
	if (is_sorted(*stack_a))
		return ;
	if (stack_size(*stack_a) == 2)
	{
		sa(stack_a);
	}
	else if (stack_size(*stack_a) == 3)
	{
		if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > (*stack_a)->next->next->value)
		{
			ra(stack_a);
			sa(stack_a);
		}
		else if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		else if ((*stack_a)->value > (*stack_a)->next->next->value)
			ra(stack_a);
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
			rra(stack_a);
	}
}
