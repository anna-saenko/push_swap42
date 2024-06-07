/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:21:33 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/07 15:21:39 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		sa(stack_a);
	else if (size == 3)
	{
		if ((*stack_a)->next->next->value > (*stack_a)->value
			&& (*stack_a)->value > (*stack_a)->next->value)
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

void	sort_above_five_elements(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;

	size_a = stack_size(*stack_a);
	while (size_a-- > 3)
	{
		pb(stack_a, stack_b);
	}
	sort_three(stack_a, 3);
	while (stack_size(*stack_b) > 0)
	{
		update_nodes_data(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	current_position(*stack_a);
	min_to_top(stack_a);
}

