#include "push_swap.h"
#include <stdio.h>

void	ft_push_b(t_nums **st_a, t_nums **st_b, t_ops **ops)
{
	if (*st_b)
	{
		while ((*st_a)->num < (*st_b)->num)
		{
			*st_b = ft_push(st_a, *st_b);
			*ops = ft_ops(*ops, "pb", 'p');
			ft_sort_b(st_b, ops);
		}
		while ((*st_b)->next)
		{
			if ((*st_b)->num < (*st_b)->next->num)
				*ops = ft_swap_ops(*st_b, *ops, "sb");
			*st_a = ft_push(st_b, *st_a);
			*ops = ft_ops(*ops, "pa", 'p');
			if ((*st_a)->num > (*st_a)->next->num)
				*ops = ft_swap_ops(*st_a, *ops, "sa");
		}
		*st_a = ft_push(st_b, *st_a);
		*ops = ft_ops(*ops, "pa", 'p');
	}
	ft_print_ops(*ops);
	ft_free(*st_a, *st_b, *ops);
}

void	ft_sort_b(t_nums **st, t_ops **ops)
{
	t_nums	*sec;
	t_nums	*last;

	sec = (*st)->next;
	if (sec && sec->next)
	{
		last = ft_last_link(*st);
		if ((*st)->num < sec->num && (*st)->num > last->num)
			*ops = ft_swap_ops(*st, *ops, "sb");
		else if ((*st)->num < sec->num && (*st)->num < last->num)
			*ops = ft_rot_ops(&st, *ops, "rb");
		else if ((*st)->num > sec->num && (*st)->num < last->num)
			*ops = ft_rrot_ops(&st,last, *ops, "rrb");
	}
	else if (sec && !sec->next && (*st)->num < sec->num)
		*ops = ft_swap_ops(*st, *ops, "sb");
}
