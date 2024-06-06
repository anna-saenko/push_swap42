/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:28:02 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/06 15:45:57 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = tmp;
	(*head)->next = tmp;
	(*head)->prev = tmp->prev;
	tmp->prev = *head;
}

void	sa(t_stack **stack_a)
{
	swap_nodes(stack_a);
	write(1, "sa\n", 3);
	current_position(stack_a);
}

void	sb(t_stack **stack_b)
{
	swap_nodes(stack_b);
	write(1, "sb\n", 3);
	current_position(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	write(1, "ss\n", 3);
	current_position(stack_a);
	current_position(stack_b);
}
