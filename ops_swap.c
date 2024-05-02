/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:28:02 by asaenko           #+#    #+#             */
/*   Updated: 2024/05/02 15:32:47 by asaenko          ###   ########.fr       */
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
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap_nodes(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	ft_printf("ss\n");
}
