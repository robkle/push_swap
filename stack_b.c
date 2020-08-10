/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:27:32 by rklein            #+#    #+#             */
/*   Updated: 2020/08/10 10:21:05 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_push(t_nums **st_a, t_nums **st_b, t_ops **ops)
{
	t_nums	*last;
	int		max;

	last = ft_last_link(*st_a);
	max = last->num;
	while ((*st_b)->next)
	{
		if ((*st_b)->num < (*st_b)->next->num)
			*ops = ft_swap_ops(*st_b, *ops, "sb");
		while ((*st_b)->num > (*st_a)->num && ((*st_a)->next &&
					((*st_b)->num > (*st_a)->next->num)))
			*ops = ft_rot_ops(&st_a, *ops, "ra");
		last = ft_last_link(*st_a);
		while (last->num != max && last->num > (*st_b)->num)
		{
			*ops = ft_rrot_ops(&st_a, last, *ops, "rra");
			last = ft_last_link(*st_a);
		}
		*st_a = ft_push(st_b, *st_a);
		*ops = ft_ops(*ops, "pa", 'p');
		if ((*st_a)->num > (*st_a)->next->num)
			*ops = ft_swap_ops(*st_a, *ops, "sa");
	}
}

void		ft_push_b(t_nums **st_a, t_nums **st_b, t_ops **ops)
{
	t_nums	*last;
	int		max;

	if (*st_b)
	{
		last = ft_last_link(*st_a);
		max = last->num;
		ft_sort_push(st_a, st_b, ops);
		last = ft_last_link(*st_a);
		while (last->num > (*st_b)->num && last->num != max)
		{
			*ops = ft_rrot_ops(&st_a, last, *ops, "rra");
			last = ft_last_link(*st_a);
		}
		*st_a = ft_push(st_b, *st_a);
		*ops = ft_ops(*ops, "pa", 'p');
		while (last->num != max)
		{
			*ops = ft_rrot_ops(&st_a, last, *ops, "rra");
			last = ft_last_link(*st_a);
		}
	}
	ft_print_ops(*ops);
	ft_free(*st_a, *st_b, *ops);
}

void		ft_sort_b(t_nums **st, t_ops **ops)
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
			*ops = ft_rrot_ops(&st, last, *ops, "rrb");
	}
	else if (sec && !sec->next && (*st)->num < sec->num)
		*ops = ft_swap_ops(*st, *ops, "sb");
}
