/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:28:51 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/06 15:44:16 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_nodes(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	tmp->prev = last;
	(*head)->prev = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate_nodes(stack_a);
	write(1, "ra\n", 3);
	current_position(stack_a);
}

void	rb(t_stack **stack_b)
{
	rotate_nodes(stack_b);
	write(1, "rb\n", 3);
	current_position(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	write(1, "rr\n", 3);
	current_position(stack_a);
	current_position(stack_b);
}

void	rotate_both(t_stack **stack_a,
					t_stack **stack_b,
					t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
	{
		rr(stack_a, stack_b);
	}
	current_position(stack_a);
	current_position(stack_b);
}
