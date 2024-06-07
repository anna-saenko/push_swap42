/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_five_a_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:16:05 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/07 12:11:17 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	**current_b;
	t_stack	**target_node;
	long	best_match;

	target_node = NULL;
	while (*stack_a != NULL)
	{
		current_b = stack_b;
		best_match = LONG_MIN;
		while (*current_b != NULL)
		{
			if ((*current_b)->value < (*stack_a)->value
				&& (*current_b)->value > best_match)
			{
				best_match = (*current_b)->value;
				target_node = current_b;
			}
			if (!(*current_b)->next)
				break ;
			(*current_b) = (*current_b)->next;
		}
		go_back_to_top(stack_b);
		if (best_match == LONG_MIN)
			(*stack_a)->target_node = find_max_stack(stack_b);
		else
			(*stack_a)->target_node = *target_node;
		if (!(*stack_a)->next)
			break ;
		(*stack_a) = (*stack_a)->next;
	}
	go_back_to_top(stack_a);
}

void	cost_analysis_a(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	while (*stack_a != NULL)
	{
		(*stack_a)->cost = (*stack_a)->index;
		if (!(*stack_a)->above_median)
			(*stack_a)->cost = size_a - (*stack_a)->index;
		if ((*stack_a)->target_node->above_median)
			(*stack_a)->cost += (*stack_a)->target_node->index;
		else
			(*stack_a)->cost += size_b - (*stack_a)->target_node->index;
		if (!(*stack_a)->next)
			break ;
		(*stack_a) = (*stack_a)->next;
	}
	go_back_to_top(stack_a);
}

void init_nodes_a(t_stack **stack_a, t_stack **stack_b)
{
	current_position(stack_a);
	current_position(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_a, stack_b);
}