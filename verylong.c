/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verylong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:22:13 by rklein            #+#    #+#             */
/*   Updated: 2020/08/10 10:31:30 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_pre_pa(t_nums ***st_a, t_nums **st_b, t_ops **ops, int *qrt)
{
	t_nums	*last;
	t_nums	*sec;

	ft_rotate_down_b(&st_b, ops, qrt[3]);
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
		}
		else if ((**st_a)->num > sec->num && (**st_a)->num > last->num)
			*ops = ft_rot_ops(st_a, *ops, "ra");
		else if ((**st_a)->num < sec->num && (**st_a)->num > last->num)
			*ops = ft_rrot_ops(st_a, last, *ops, "rra");
	}
	ft_push_b(*st_a, st_b, ops);
}

static void	ft_push_top(t_nums ***st_a, t_nums **st_b, t_ops **ops)
{
	*st_b = ft_push(*st_a, *st_b);
	*ops = ft_ops(*ops, "pb", 'p');
	if ((*st_b)->num < (*st_b)->next->num)
		*ops = ft_swap_ops(*st_b, *ops, "sb");
}

static void	ft_push_bottom(t_nums ***st_a, t_nums **st_b, t_ops **ops)
{
	*st_b = ft_push(*st_a, *st_b);
	*ops = ft_ops(*ops, "pb", 'p');
	*ops = ft_rot_ops(&st_b, *ops, "rb");
}

void		ft_ps_rest_long(t_nums ***st_a, t_nums **st_b, t_ops **ops,
		int *qrt)
{
	int	split[6];
	int	count;

	ft_presort(**st_a, split);
	count = 0;
	while (count < 2 * (split[0] / 3))
	{
		if ((**st_a)->num < split[1])
		{
			ft_push_top(st_a, st_b, ops);
			count++;
		}
		else if ((**st_a)->num >= split[1] && (**st_a)->num <= split[2])
		{
			ft_push_bottom(st_a, st_b, ops);
			count++;
		}
		else
			*ops = ft_rot_ops(st_a, *ops, "ra");
	}
	ft_pre_pa(st_a, st_b, ops, qrt);
}
