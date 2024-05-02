/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:08:13 by asaenko           #+#    #+#             */
/*   Updated: 2024/05/02 12:42:52 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current = stack;

	while (current != NULL)
	{
		printf("[%02d]: %d -> ", current->index, current->value);
		current = current->next;
	}
	printf("\n");
}

int is_sorted(t_stack *head)
{
	t_stack	*current;

	if (head == NULL)
	{
		return 0;
	}
	current = head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
		{
			return 0;
		}
		current = current->next;
	}
	return 1;
}
