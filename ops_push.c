/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:27:53 by asaenko           #+#    #+#             */
/*   Updated: 2024/05/02 15:31:20 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node (t_stack **head, t_stack *node)
{
	t_stack	*tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
	node->prev = tmp;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	push_node(stack_b, tmp);
	ft_printf("pb\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	push_node(stack_a, tmp);
	ft_printf("pa\n");
}
