#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void	display_error(void)
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

char	**parse_args(int argc, char **argv)
{
	char	**args;
	long	temp;
	int		i;
	int		j;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!ft_isnum(args[i]))
			display_error();
		temp = ft_atoi(args[i]);
		printf("temp: %ld\n", temp);
		if (is_double(temp, args, i))
			display_error();
		if (temp > INT_MAX || temp < INT_MIN)
			display_error();
		i++;
	}
	return (args);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **args;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	args = parse_args(argc, argv);
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", args[i]);
	}
	return (0);
}