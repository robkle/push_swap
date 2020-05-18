#include "push_swap.h"

t_nums	*ft_last_link(t_nums *lst)
{
	t_nums	*current;
	t_nums	*next;

	current = lst;
	next = lst->next;
	while(next)
	{
		current = current->next;
		next = next->next;
	}
	return(current);
}

t_ops	*ft_last_op(t_ops *lst)
{
	t_ops	*current;
	t_ops	*next;

	current = lst;
	next = lst->next;
	while(next)
	{
		current = current->next;
		next = next->next;
	}
	return(current);
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
