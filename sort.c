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
	stack_b = NULL;
}

void	sort_three(t_stack **stack_a, int size)
{
	if (size == 2)
	{
		sa(stack_a);
	}
	else if (size == 3)
	{
		if ((*stack_a)->next->next->value > (*stack_a)->value && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
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

int	find_min(t_stack *stack)
{
	t_stack	*current;
	int		min;

	min = INT_MAX;
	current = stack;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_stack	*current;
	int		max;

	max = INT_MIN;
	current = stack;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	shortest_path_to_top(t_stack *stack, int value)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		if (current->value == value)
			break ;
		i++;
		current = current->next;
	}
	if (i < stack_size(stack) / 2)
		return (1);
	return (0);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->value == find_min(*stack_a))
			pb(stack_a, stack_b);
//		else if (shortest_path_to_top(*stack_a, find_min(*stack_a)) == 1)
//			ra(stack_a);
		else
			rra(stack_a);
	}
	sort_three(stack_a, 3);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
