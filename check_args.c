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
	int	temp;

	j = 1;
	while (j < i)
	{
		temp = ft_atoi(args[j]);
		if (num == temp)
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
void	check_args(int argc, char **argv)
{
	char	**args;
	long	num;
	int		i;

	args = prepare_args(argc, argv);
	i = 0;
	while (args[i] != NULL)
	{
		num = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || is_too_big(num) || is_double(num, args, i))
			display_error();
		i++;
	}
}
