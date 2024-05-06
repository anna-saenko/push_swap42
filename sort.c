#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size <= 3)
	{
		sort_three(stack_a, size);
		return ;
	}
	else if (size <= 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	else
	{
		sort_beyond_five(stack_a, stack_b);
		return ;
	}
	stack_b = NULL;
}

void	sort_three(t_stack **stack_a, int size)
{
	if (is_sorted(*stack_a))
		return ;
	if (size == 2)
	{
		sa(stack_a);
	}
	else if (size == 3)
	{
		if ((*stack_a)->next->next->value > (*stack_a)->value && (*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a);
		}
		else if ((*stack_a)->value > (*stack_a)->next->value)
		{
			ra(stack_a);
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
		}
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			rra(stack_a);
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
		}
	}
}

int	find_min(t_stack *stack)
{
	t_stack	*current;
	int		min;

	min = INT_MAX;
	current = stack;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_stack	*current;
	int		max;

	max = INT_MIN;
	current = stack;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	shortest_path_to_top(t_stack *stack, int value)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		if (current->value == value)
			break ;
		i++;
		current = current->next;
	}
	if (i < stack_size(stack) / 2)
		return (1);
	return (0);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->value == find_min(*stack_a))
			pb(stack_a, stack_b);
//		else if (shortest_path_to_top(*stack_a, find_min(*stack_a)) == 1)
//			ra(stack_a);
		else
			rra(stack_a);
	}
	sort_three(stack_a, 3);
	while (stack_size(*stack_b) > 0)
	{
		if ((*stack_b)->value == find_max(*stack_b))
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
}

int	quick_sort_partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		j++;
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = quick_sort_partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

static int	find_median(t_stack *stack)
{
	t_stack	*current;
	int		*arr;
	int		i;
	int		median;

	arr = malloc(sizeof(int) * stack_size(stack));
	if (!arr)
		exit(1);
	i = 0;
	current = stack;
	while (current != NULL)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	quick_sort(arr, 0, stack_size(stack) - 1);
	median = arr[stack_size(stack) / 2];
	free(arr);
	return (median);
}

void	sort_beyond_five(t_stack **stack_a, t_stack **stack_b)
{
	int	median;
	int	i;
	int	size;

	median = find_median(*stack_a);
	size = stack_size(*stack_a);
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->value < median)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	sort_three(stack_a, stack_size(*stack_a));
	while (stack_size(*stack_b) > 0)
	{
		if ((*stack_b)->value == find_max(*stack_b))
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
}
