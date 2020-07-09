/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:35:53 by rklein            #+#    #+#             */
/*   Updated: 2020/06/04 12:47:05 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nums	*ft_last_link(t_nums *lst)
{
	t_nums	*current;
	t_nums	*next;

	current = lst;
	next = lst->next;
	while (next)
	{
		current = current->next;
		next = next->next;
	}
	return (current);
}

t_ops	*ft_last_op(t_ops *lst)
{
	t_ops	*current;
	t_ops	*next;

	current = lst;
	next = lst->next;
	while (next)
	{
		current = current->next;
		next = next->next;
	}
	return (current);
}

char	**ft_parcpy(int ac, char **av)
{
	char	**par;
	int		i;

	if (!(par = (char **)malloc(sizeof(char *) * ac)))
		return (NULL);
	i = 0;
	av++;
	while (*av)
	{
		par[i++] = ft_strdup(*av);
		av++;
	}
	par[i] = NULL;
	return (par);
}

void	ft_free(t_nums *st_a, t_nums *st_b, t_ops *ops)
{
	t_nums	*tmp_n;
	t_ops	*tmp_o;

	while (st_a)
	{
		tmp_n = st_a->next;
		free(st_a);
		st_a = tmp_n;
	}
	while (st_b)
	{
		tmp_n = st_b->next;
		free(st_b);
		st_b = tmp_n;
	}
	while (ops)
	{
		tmp_o = ops->next;
		free(ops->op);
		free(ops);
		ops = tmp_o;
	}
}
