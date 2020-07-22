#include "push_swap.h"

static void	ft_splitsort_b(t_nums **st, t_ops **ops, int *qrt)
{
	t_nums	*sec;

	sec = (*st)->next;
	if (sec && sec->next)
	{
		if ((*st)->num <= qrt[2])
			*ops = ft_rot_ops(&st, *ops, "rb");
		else if ((*st)->num < sec->num)
			*ops = ft_swap_ops(*st, *ops, "sb");
	}
	else if (sec && !sec->next && (*st)->num < sec->num)
		*ops = ft_swap_ops(*st, *ops, "sb");
}

static void	ft_ps_rest(t_nums **st_a, t_nums *st_b, t_ops *ops, int *qrt)
{
	t_nums	*sec;
	t_nums	*last;

	while (!ft_order(*st_a))
	{
		sec = (*st_a)->next;
		last = ft_last_link(*st_a);
		if ((*st_a)->num > sec->num && (*st_a)->num < last->num)
			ops = ft_swap_ops(*st_a, ops, "sa");
		else if ((*st_a)->num < sec->num && (*st_a)->num < last->num)
		{
			st_b = ft_push(st_a, st_b);
			ops = ft_ops(ops, "pb", 'p');
			ft_splitsort_b(&st_b, &ops, qrt);
		}
		else if ((*st_a)->num > sec->num && (*st_a)->num > last->num)
			ops = ft_rot_ops(&st_a, ops, "ra");
		else if ((*st_a)->num < sec->num && (*st_a)->num > last->num)
			ops = ft_rrot_ops(&st_a, last, ops, "rra");
	}
	ft_push_b(st_a, &st_b, &ops);
}

void	ft_ps_long_a(t_nums **st_a, int *qrt)
{
	t_ops	*ops;
	t_nums	*st_b;
	int		count;
	
	ops = NULL;
	st_b = NULL;
	count = 0;
	while (count < qrt[0] / 2)
	{
		if ((*st_a)->num <= qrt[1])
		{
			st_b = ft_push(st_a, st_b);
			ops = ft_ops(ops, "pb", 'p');
			ft_splitsort_b(&st_b, &ops, qrt);
			count++;
		}
		else
			ops = ft_rot_ops(&st_a, ops, "ra");
	}
	//sort ft for high values
	ft_ps_rest(st_a, st_b, ops, qrt);
}
