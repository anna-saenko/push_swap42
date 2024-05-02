/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:29:21 by asaenko           #+#    #+#             */
/*   Updated: 2024/05/02 15:42:12 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		check_args(argc, argv);
		args = prepare_args(argc, argv);
		printf("Args: %p\n", args);
		stack_a = parse_args_to_linked_list(args);
		if (is_sorted(stack_a))
		{
			printf("Stack is sorted\n");
		}
		else
		{
			printf("Stack is not sorted\n");
		}
		printf("Stack_a: %p\n", stack_a);
		print_stack(stack_a);
		sort_stack(&stack_a, &stack_b);
		printf("Stack_a: %p\n", stack_a);
		print_stack(stack_a);
		free_stack(stack_a);
	}
	return (0);
}