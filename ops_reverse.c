/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:28:16 by asaenko           #+#    #+#             */
/*   Updated: 2024/05/02 15:31:48 by asaenko          ###   ########.fr       */
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
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_nodes(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_nodes(stack_a);
	reverse_rotate_nodes(stack_b);
	ft_printf("rrr\n");
}
