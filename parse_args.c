#include "push_swap.h"

char	**prepare_args(int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = (char **)malloc(sizeof(char *) * (argc));
		if (!args)
			return (NULL);
		i = 0;
		while (i < argc - 1)
		{
			args[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		args[i] = NULL;
	}
	return (args);
}


static t_stack	*create_node(int value, int index, t_stack* prev)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	head->value = value;
	head->index = index;
	head->next = NULL;
	if (prev)
	{
		prev->next = head;
	}
	return head;
}

t_stack	*parse_args_to_linked_list(char **args)
{
	t_stack	*head;
	t_stack	*prev_node;
	t_stack	*cur_node;
	int		i;

	i = 0;
	head = create_node(ft_atoi(args[i]), i, NULL);
	prev_node = head;
	++i;
	while(args[i] != NULL)
	{
		cur_node = create_node(ft_atoi(args[i]), i, prev_node);
		prev_node = cur_node;
		++i;
	}
	free_char_arr(args);
	args = NULL;
	return (head);
}
