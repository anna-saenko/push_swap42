/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_five_move_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:23:28 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/07 15:24:45 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_to_top(t_stack **stack)
{
	t_stack	*min;

	min = find_min_stack(stack);
	if (min->above_median)
	{
		while (*stack != min)
			ra(stack);
	}
	else
	{
		while (*stack != min)
			rra(stack);
	}
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_nodes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
	{
		rotate_both(stack_a, stack_b, cheapest_node);
	}
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
	{
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	}
	prep_for_push(stack_a, cheapest_node->target_node, 'a');
	prep_for_push(stack_b, cheapest_node, 'b');
	pa(stack_a, stack_b);
}
