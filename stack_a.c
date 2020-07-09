/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:01:36 by rklein            #+#    #+#             */
/*   Updated: 2020/06/04 12:46:52 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nums		*ft_make_list(char **par)
{
	t_nums	*lst;
	t_nums	*begin;
	int		num;
	int		i;

	num = -1;
	while (par[++num])
		;
	if (!(lst = (t_nums*)malloc(sizeof(t_nums))))
		return (NULL);
	begin = lst;
	i = -1;
	while (++i < num - 1)
	{
		lst->num = ft_atoi(par[i]);
		if (!(lst->next = (t_nums*)malloc(sizeof(t_nums))))
			return (NULL);
		lst = lst->next;
	}
	lst->num = ft_atoi(par[i]);
	lst->next = NULL;
	return (begin);
}

int			ft_order(t_nums *stack)
{
	t_nums	*lst;

	lst = stack->next;
	while (lst)
	{
		if (stack->num > lst->num)
			return (0);
		stack = stack->next;
		lst = lst->next;
	}
	return (1);
}
