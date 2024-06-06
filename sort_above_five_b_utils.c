/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_five_b_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:17:17 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/06 16:43:39 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	**current_a;
	t_stack	**target_node;
	long	best_match;

	while (*stack_b)
	{
		current_a = stack_a;
		best_match = LONG_MAX;
		while (*current_a)
		{
			if ((*current_a)->value > (*stack_b)->value
				&& (*current_a)->value < best_match)
			{
				best_match = (*current_a)->value;
				target_node = current_a;
			}
			if (!(*current_a)->next)
				break ;
			(*current_a) = (*current_a)->next;
		}
		go_back_to_top(stack_a);
		if (best_match == LONG_MAX)
			(*stack_b)->target_node = find_min_stack(stack_a);
		else
			(*stack_b)->target_node = *target_node;
		if (!(*stack_b)->next)
			break ;
		(*stack_b) = (*stack_b)->next;
	}
	go_back_to_top(stack_b);
}

void	cost_analysis_b(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	while (*stack_b)
	{
		(*stack_b)->cost = (*stack_b)->index;
		if (!(*stack_b)->above_median)
			(*stack_b)->cost = size_b - (*stack_b)->index;
		if ((*stack_b)->target_node->above_median)
			(*stack_b)->cost += (*stack_b)->target_node->index;
		else
			(*stack_b)->cost += size_a - (*stack_b)->target_node->index;
		if (!(*stack_b)->next)
			break ;
		(*stack_b) = (*stack_b)->next;
	}
	go_back_to_top(stack_b);
}

void init_nodes_b(t_stack **stack_a, t_stack **stack_b)
{
	current_position(stack_a);
	current_position(stack_b);
	set_target_b(stack_a, stack_b);
	cost_analysis_b(stack_b, stack_a);
	set_cheapest(stack_b);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b);
}