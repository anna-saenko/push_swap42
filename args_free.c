/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:26:36 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/07 15:26:38 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_char_arr(char **arr)
{
	unsigned	i;

	if (arr == NULL)
		return;
	i = 0;
	while(arr[i] != NULL)
	{
		free(arr[i++]);
	}
	free(arr);
	arr = NULL;
}

void	free_stack(t_stack *stack)
{
	t_stack	*current = stack;

	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	stack = NULL;
}