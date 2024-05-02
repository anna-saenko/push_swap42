/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:28:59 by asaenko           #+#    #+#             */
/*   Updated: 2024/05/02 15:41:19 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

char	**prepare_args(int argc, char **argv);
//check_args.c
void	check_args(int argc, char **argv);

t_stack	*parse_args_to_linked_list(char **args);
//free_funcs.c
void	free_char_arr(char **arr);
void	free_stack(t_stack *stack);
//utils.c
void	print_stack(t_stack *stack);
int is_sorted(t_stack *head);
int	stack_size(t_stack *head);
//operations: push_ops.c swap_ops.c rotate_ops.c reverse_ops.c
void	push_node(t_stack **head, t_stack *node);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);

void	swap_nodes(t_stack **head);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	rotate_nodes(t_stack **head);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate_nodes(t_stack **head);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);

#endif