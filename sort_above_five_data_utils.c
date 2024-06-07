/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_five_data_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:09:43 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/07 15:10:26 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_position(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long			best_match_index;

	while (stack_b != NULL)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			stack_b->target_node = find_min_stack(&stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (stack_b != NULL)
	{
		stack_b->cost = stack_b->index;
		if (!stack_b->above_median)
			stack_b->cost = size_b - stack_b->index;
		if (stack_b->target_node->above_median)
			stack_b->cost += stack_b->target_node->index;
		else
			stack_b->cost += size_a - stack_b->target_node->index;
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	max_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	max_value = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->cost < max_value)
		{
			max_value = stack->cost;
			cheapest_node = stack;
		}
		if (!stack->next)
			break ;
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	update_nodes_data(t_stack *stack_a, t_stack *stack_b)
{
	current_position(stack_a);
	current_position(stack_b);
	set_target(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_cheapest(stack_b);
}
