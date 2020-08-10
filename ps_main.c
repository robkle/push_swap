/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:21:17 by rklein            #+#    #+#             */
/*   Updated: 2020/07/07 15:25:08 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_a(t_nums **st_a)
{
	t_ops	*ops;
	t_nums	*st_b;
	t_nums	*sec;
	t_nums	*last;

	ops = NULL;
	st_b = NULL;
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
			ft_sort_b(&st_b, &ops);
		}
		else if ((*st_a)->num > sec->num && (*st_a)->num > last->num)
			ops = ft_rot_ops(&st_a, ops, "ra");
		else if ((*st_a)->num < sec->num && (*st_a)->num > last->num)
			ops = ft_rrot_ops(&st_a, last, ops, "rra");
	}
	ft_push_b(st_a, &st_b, &ops);
}

int		main(int argc, char **argv)
{
	t_nums	*stack_a;
	char	**par;
	int		qrt[6];

	if (argc >= 2)
	{
		par = argc == 2 ? ft_strsplit(argv[1], ' ') : ft_parcpy(argc, argv);
		if (!ft_validator(par) || !(stack_a = ft_make_list(par)))
			return (0);
		ft_presort(stack_a, qrt);
		if (!ft_order(stack_a))
		{
			if (qrt[0] <= 20)
				ft_push_swap_a(&stack_a);
			else
				ft_ps_long_a(&stack_a, qrt);
		}
	}
	return (0);
}
