/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:13:37 by rklein            #+#    #+#             */
/*   Updated: 2020/08/10 10:15:11 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rotate_down_b(t_nums ***st_b, t_ops **ops, int split)
{
	t_nums	*last;

	last = ft_last_link(**st_b);
	while (last->num > split)
	{
		*ops = ft_rrot_ops(st_b, last, *ops, "rrb");
		if ((**st_b)->num < (**st_b)->next->num)
			*ops = ft_swap_ops(**st_b, *ops, "sb");
		last = ft_last_link(**st_b);
	}
}

static void	ft_splitsort_b(t_nums **st, t_ops **ops, int lt, int split)
{
	t_nums	*sec;

	sec = (*st)->next;
	if (sec && sec->next)
	{
		if ((*st)->num <= lt && (*st)->num <= split)
			*ops = ft_rot_ops(&st, *ops, "rb");
		else if ((*st)->num > lt && (*st)->num >= split)
			*ops = ft_rot_ops(&st, *ops, "rb");
	}
	else if (sec && !sec->next && (*st)->num < sec->num)
		*ops = ft_swap_ops(*st, *ops, "sb");
	if ((*st)->next && (*st)->num < (*st)->next->num)
		*ops = ft_swap_ops(*st, *ops, "sb");
}

static void	ft_ps_rest(t_nums ***st_a, t_nums **st_b, t_ops **ops, int *qrt)
{
	t_nums	*sec;
	t_nums	*last;

	while (!ft_order(**st_a))
	{
		sec = (**st_a)->next;
		last = ft_last_link(**st_a);
		if ((**st_a)->num > sec->num && (**st_a)->num < last->num)
			*ops = ft_swap_ops(**st_a, *ops, "sa");
		else if ((**st_a)->num < sec->num && (**st_a)->num < last->num)
		{
			*st_b = ft_push(*st_a, *st_b);
			*ops = ft_ops(*ops, "pb", 'p');
			ft_splitsort_b(st_b, ops, qrt[1], qrt[5]);
		}
		else if ((**st_a)->num > sec->num && (**st_a)->num > last->num)
			*ops = ft_rot_ops(st_a, *ops, "ra");
		else if ((**st_a)->num < sec->num && (**st_a)->num > last->num)
			*ops = ft_rrot_ops(st_a, last, *ops, "rra");
	}
	ft_rotate_down_b(&st_b, ops, qrt[3]);
	ft_push_b(*st_a, st_b, ops);
}

static void	ft_ps_high(t_nums ***st_a, t_nums **st_b, t_ops **ops, int *qrt)
{
	int		count;

	count = 0;
	while (count < qrt[0] / 3)
	{
		if ((**st_a)->num <= qrt[2])
		{
			*st_b = ft_push(*st_a, *st_b);
			*ops = ft_ops(*ops, "pb", 'p');
			if ((*st_b)->num >= qrt[4])
				*ops = ft_rot_ops(&st_b, *ops, "rb");
			count++;
		}
		else
			*ops = ft_rot_ops(st_a, *ops, "ra");
	}
	ft_rotate_down_b(&st_b, ops, qrt[3]);
}

void		ft_ps_long_a(t_nums **st_a, int *qrt)
{
	t_ops	*ops;
	t_nums	*st_b;
	int		count;

	ops = NULL;
	st_b = NULL;
	count = 0;
	while (count < qrt[0] / 3)
	{
		if ((*st_a)->num <= qrt[1])
		{
			st_b = ft_push(st_a, st_b);
			ops = ft_ops(ops, "pb", 'p');
			ft_splitsort_b(&st_b, &ops, qrt[1], qrt[3]);
			count++;
		}
		else
			ops = ft_rot_ops(&st_a, ops, "ra");
	}
	ft_ps_high(&st_a, &st_b, &ops, qrt);
	if (qrt[0] < 100)
		ft_ps_rest(&st_a, &st_b, &ops, qrt);
	else
		ft_ps_rest_long(&st_a, &st_b, &ops, qrt);
}
