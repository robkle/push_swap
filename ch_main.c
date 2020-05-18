#include "push_swap.h"
#include <stdio.h>

static int	ft_validator(char **av)
{
	if (!ft_valid_num(av))
	{
		ft_putendl("Error");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_nums	*stack_a;
	char	*line;
	t_ops	*ops;
	
	if (argc > 2)
	{
		if (!ft_validator(argv))
			return (0);
		if (!(stack_a = ft_make_list(argc, argv)))
			return (0);
		ops = NULL;
		while (get_next_line(0, &line))
		{	
			if (!ft_isop(line))
			{
				ft_putendl("Error");
				ft_free(stack_a, NULL, ops);
				return (0);
			}	
			ops = ft_ops(ops, line, 'c');
		}	
	}
	ft_checker(&stack_a, ops);
	return (0);
}
