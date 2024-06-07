/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:28:59 by asaenko           #+#    #+#             */
/*   Updated: 2024/06/07 15:33:31 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
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
//args_free.c
void	free_char_arr(char **arr);
void	free_stack(t_stack *stack);
//utils.c
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

//sort_algos.c
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a, int size);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_above_five_elements(t_stack **stack_a, t_stack **stack_b);
//sort_five_utils.c
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		shortest_path_to_top(t_stack *stack, int value);
//sort_above_five_utils.c
t_stack	*get_cheapest(t_stack *stack);
t_stack	*find_max_stack(t_stack **stack);
t_stack	*find_min_stack(t_stack **stack);
//sort_above_five_data_utils.c
void	set_cheapest(t_stack *stack);
void	current_position(t_stack *stack);
void	set_target(t_stack *stack_a, t_stack *stack_b);
void	set_cost(t_stack *stack_a, t_stack *stack_b);
void	update_nodes_data(t_stack *stack_a, t_stack *stack_b);
//sort_above_five_move_utils.c
void	min_to_top(t_stack **stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	move_nodes(t_stack **stack_a, t_stack **stack_b);

#endif