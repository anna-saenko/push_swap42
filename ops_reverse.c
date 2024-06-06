/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:28:16 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/06 15:44:48 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_nodes(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->prev = tmp;
	*head = tmp;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate_nodes(stack_a);
	write(1, "rra\n", 4);
	current_position(stack_a);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_nodes(stack_b);
	write(1, "rrb\n", 4);
	current_position(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_nodes(stack_a);
	reverse_rotate_nodes(stack_b);
	write(1, "rrr\n", 4);
	current_position(stack_a);
	current_position(stack_b);
}
void	rev_rotate_both(t_stack **stack_a,
						t_stack **stack_b,
						t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
	{
		rrr(stack_a, stack_b);
	}
	current_position(stack_a);
}