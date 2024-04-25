#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	check_args(argc, argv);
	args = prepare_args(argc, argv);
	while (args[i] != NULL)
	{
		printf("%s\n", args[i]);
		free(args[i]);
		i++;
	}
	free(args);
	return (0);
}