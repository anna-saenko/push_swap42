#include "push_swap.h"

void	rotate_nodes(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*head)->prev;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate_nodes(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate_nodes(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	ft_printf("rr\n");
}
