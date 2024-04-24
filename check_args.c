#include "push_swap.h"

static void	display_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
static int	ft_isnum(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
static int	is_double(int num, char **args, int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (num == ft_atoi(args[j]))
			return (1);
		j++;
	}
	return (0);
}

static int	is_too_big(int num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

t_stack	*check_args(int argc, char **argv)
{
	char	**args;
	long	num;
	int		i;
	t_stack	*head;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || is_too_big(num) || is_double(num, args, i))
			display_error();
		else
		{
			head = (t_stack *)malloc(sizeof(t_stack));
			head->value = num;
			head->index = i;
			if (i == argc - 1)
				head->next = NULL;
			else
				head->next = head + 1;
		}
		i++;
	}
	return (head);
}
