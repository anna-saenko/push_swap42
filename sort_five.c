/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:48:06 by asaenko           #+#    #+#             */
/*   Updated: 2024/05/30 15:04:57 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (is_sorted(*stack_a))
		return ;
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->value == find_min(*stack_a))
			pb(stack_a, stack_b);
		else if (shortest_path_to_top(*stack_a, find_min(*stack_a)) == 1)
			ra(stack_a);
		else
			rra(stack_a);
	}
	sort_three(stack_a, 3);
	while (stack_size(*stack_b) > 0)
	{
		if ((*stack_b)->value == find_max(*stack_b))
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
}
