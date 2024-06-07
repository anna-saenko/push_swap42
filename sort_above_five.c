/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:54:37 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/07 12:10:57 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_back_to_top(t_stack **stack)
{
	while ((*stack)->prev)
		(*stack) = (*stack)->prev;
}

t_stack	*find_max_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*max;

	current = *stack;
	max = current;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

t_stack	*find_min_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*min;

	current = *stack;
	min = current;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

void	min_to_top(t_stack **stack)
{
	t_stack	*min;

	min = find_min_stack(stack);
	while ((*stack)->value != min->value)
	{
		if ((*stack)->above_median)
			ra(stack);
		else
			rra(stack);
	}
}

void	current_position(t_stack **stack)
{
	int	i;
	int	median;

	i = 0;
	if (!*stack)
		return ;
	median = stack_size(*stack) / 2;
	while (*stack != NULL)
	{
		(*stack)->index = i;
		if (i <= median)
			(*stack)->above_median = true;
		else
			(*stack)->above_median = false;
		if (!(*stack)->next)
			break ;
		(*stack) = (*stack)->next;
		++i;
	}
	go_back_to_top(stack);
}

void	set_cheapest(t_stack **stack)
{
	long	cheapest;
	t_stack	**cheapest_stack;

	if (!*stack)
		return ;
	cheapest = LONG_MAX;
	while (*stack != NULL)
	{
		if ((*stack)->cost < cheapest)
		{
			cheapest = (*stack)->cost;
			cheapest_stack = stack;
		}
		if (!(*stack)->next)
			break ;
		(*stack) = (*stack)->next;
	}
	(*cheapest_stack)->cheapest = true;
	go_back_to_top(stack);
}

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*current;
	t_stack	*cheapest;

	current = stack;
	cheapest = current;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
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


void	sort_above_five_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	a_len;

	a_len = stack_size(*stack_a);
	if (a_len-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (a_len-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (a_len-- > 3 && !is_sorted(*stack_a))
	{
		init_nodes_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a, 3);
	print_stack(*stack_a);
	while (stack_size(*stack_b) > 0)
	{
		init_nodes_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_position(stack_a);
	min_to_top(stack_a);
}
