/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:54:56 by rklein            #+#    #+#             */
/*   Updated: 2020/06/01 14:57:43 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_mod_ops(t_ops *ops, char *str)
{
	t_ops	*tmp;

	tmp = ops->next;
	free(ops->op);
	ops->op = ft_strdup(str);
	ops->next = tmp->next;
	free(tmp->op);
	free(tmp);
}

void		ft_print_ops(t_ops *ops)
{
	t_ops	*begin;
	t_ops	*tmp;

	begin = ops;
	while (ops->next)
	{
		tmp = ops->next;
		if (!ft_strcmp(ops->op, "rrb") && !ft_strcmp(tmp->op, "rra"))
			ft_mod_ops(ops, "rrr");
		else if (!ft_strcmp(ops->op, "rb") && !ft_strcmp(tmp->op, "ra"))
			ft_mod_ops(ops, "rr");
		else if (!ft_strcmp(ops->op, "sb") && !ft_strcmp(tmp->op, "sa"))
			ft_mod_ops(ops, "ss");
		else if (!ft_strcmp(ops->op, "sa") && !ft_strcmp(tmp->op, "sb"))
			ft_mod_ops(ops, "ss");
		ops = ops->next;
	}
	while (begin)
	{
		ft_putendl(begin->op);
		begin = begin->next;
	}
}
