/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:28:59 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/06 15:12:52 by asaenko          ###   ########.fr       */
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
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//check_args.c
char	**prepare_args(int argc, char **argv);
//parse_args.c
void	check_args(int argc, char **argv);
t_stack	*parse_args_to_linked_list(char **args);
//free_funcs.c
void	free_char_arr(char **arr);
void	free_stack(t_stack *stack);
//utils.c
void	print_stack(t_stack *stack);
int		is_sorted(t_stack *head);
int		stack_size(t_stack *head);
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
void	rotate_both(t_stack **stack_a,
					t_stack **stack_b,
					t_stack *cheapest_node);

void	reverse_rotate_nodes(t_stack **head);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate_both(t_stack **stack_a,
						t_stack **stack_b,
						t_stack *cheapest_node);

//sort.c
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a, int size);
//sort_five.c
void	sort_five(t_stack **stack_a, t_stack **stack_b);
int		shortest_path_to_top(t_stack *stack, int value);

//sort_above_five.c
void	sort_above_five_elements(t_stack **stack_a, t_stack **stack_b);
void	set_cheapest(t_stack **stack);
void	go_back_to_top(t_stack **stack);
void	current_position(t_stack **stack);
void	min_to_top(t_stack **stack);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
t_stack	*find_max_stack(t_stack **stack);
t_stack	*find_min_stack(t_stack **stack);

//sort_above_five_a_utils.c
void	init_nodes_a(t_stack **stack_a, t_stack **stack_b);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	set_target_a(t_stack **stack_a, t_stack **stack_b);
void	cost_analysis_a(t_stack **stack_a, t_stack **stack_b);
//sort_above_five_b_utils.c
void	init_nodes_b(t_stack **stack_a, t_stack **stack_b);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	set_target_b(t_stack **stack_a, t_stack **stack_b);
void	cost_analysis_b(t_stack **stack_a, t_stack **stack_b);
//sort_utils.c
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);

#endif