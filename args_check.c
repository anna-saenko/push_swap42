/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaenko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:30:54 by asaenko           #+#    #+#             */
/*   Updated: 2024/05/06 16:10:36 by asaenko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
static int	is_double(char **args)
{
	int i;
	int j;

	i = 0;
	while (args[i] != NULL)
	{
		j = i + 1;
		while (args[j] != NULL)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_too_big(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

void	check_args(int argc, char **argv)
{
	char	**args;
	long	num;
	int		i;

	args = prepare_args(argc, argv);
	if (!args)
		display_error();
	i = 0;
	if (is_double(args))
	{
		free_char_arr(args);
		display_error();
	}
	while (args[i] != NULL)
	{
		num = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || !num || is_too_big(num))
		{
			free_char_arr(args);
			display_error();
		}
		i++;
	}
}
