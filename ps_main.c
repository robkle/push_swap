#include "push_swap.h"
#include <stdio.h>

void	ft_push_swap_a(t_nums **st_a)
{
	t_ops	*ops;
	t_nums	*st_b;
	t_nums	*sec;
	t_nums	*last;

	ops = NULL;
	st_b = NULL;
	while (ft_order(*st_a) == 0)
	{
		sec = (*st_a)->next;
		last = ft_last_link(*st_a);
		if ((*st_a)->num > sec->num && (*st_a)->num < last->num)
			ops = ft_swap_ops(*st_a, ops, "sa");
		else if ((*st_a)->num < sec->num && (*st_a)->num < last->num)
		{
			st_b = ft_push(st_a, st_b);
			ops = ft_ops(ops, "pb", 'p');
			ft_sort_b(&st_b, &ops);
		}
		else if ((*st_a)->num > sec->num && (*st_a)->num > last->num)
			ops = ft_rot_ops(&st_a, ops, "ra");
		else if ((*st_a)->num < sec->num && (*st_a)->num > last->num)
			ops = ft_rrot_ops(&st_a, last, ops, "rra");
	}
	ft_push_b(st_a, &st_b, &ops);
}

int	main(int argc, char **argv)
{
	
	t_nums	*stack_a;

	if (argc > 2)
	{
		if(!ft_valid_num(argv))
		{
			ft_putstr("Error\n");
			return (0);
		}
		if(!(stack_a = ft_make_list(argc, argv)))
			return (0);
		ft_push_swap_a(&stack_a);
	}	
	return (0);
}
