#include "push_swap.h"
#include <stdio.h>

t_ops	*ft_rrot_ops(t_nums ***stack, t_nums *last, t_ops *ops, char *str)
{
	t_nums	*begin;
	t_nums	*new;
	t_nums	*term;
	t_nums	*tmp;

	term = (**stack)->next;
	new = malloc(sizeof(t_nums));
	begin = new;
	new->num = last->num;
	while (term)
	{
		new->next = malloc(sizeof(t_nums));
		new = new->next;
		new->num = (**stack)->num;
		tmp = (**stack)->next;
		free (**stack);
		**stack = tmp;
		term = term->next;
	}
	new->next = NULL;
	free (tmp);
	**stack = begin;
	return (ft_ops(ops, str, 'p'));
} 

t_ops	*ft_rot_ops(t_nums ***stack, t_ops *ops, char *str)
{
	t_nums	*begin;
	t_nums	*start;
	t_nums	*tmp;

	begin = **stack;
	start = (**stack)->next;
	tmp = (**stack)->next;
	while (tmp)
	{
		tmp = tmp->next;
		**stack = (**stack)->next;
	}
	(**stack)->next = malloc(sizeof(t_nums));
	(**stack)->next->num = begin->num;
	(**stack)->next->next = NULL;
	free (begin);
	**stack = start;
	return (ft_ops(ops, str, 'p'));
}

t_nums	*ft_push(t_nums **src, t_nums *dst)
{
	t_nums	*begin_src;
	t_nums	*new;

	if (dst == NULL)
	{
		new = malloc(sizeof(t_nums));
		new->num = (*src)->num;
		new->next = NULL;
	}
	else
	{
		new = malloc(sizeof(t_nums));
		new->num = (*src)->num;
		new->next = dst;
	}
	begin_src = *src;
	*src = (*src)->next;
	free(begin_src);
	begin_src = NULL;
	return (new);
}

t_ops	*ft_swap_ops(t_nums *stack, t_ops *ops, char *str)
{
	int	tmp;

	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	return (ft_ops(ops, str, 'p'));
}
