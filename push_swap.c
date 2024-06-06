/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:29:21 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/03 15:17:39 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	args = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		check_args(argc, argv);
		args = prepare_args(argc, argv);
		stack_a = parse_args_to_linked_list(args);
		print_stack(stack_a);
		sort_stack(&stack_a, &stack_b);
		print_stack(stack_a);
		free_stack(stack_a);
	}
	return (0);
}
