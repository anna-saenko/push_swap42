/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:27:53 by asaenko           #+#    #+#             */
/*   Updated: 2024/05/03 14:01:31 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node (t_stack **to, t_stack *from)
{
	if (!from)
		return ;
	if (!*to)
	{
		*to = from;
		(*to)->next = NULL;
		(*to)->prev = NULL;
	}
	else
	{
		from->next = *to;
		from->prev = NULL;
		(*to)->prev = from;
		*to = from;
	}
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
	write(1, "pb\n", 3);
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
	write(1, "pa\n", 3);
}
