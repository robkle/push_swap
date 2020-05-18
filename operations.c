#include "push_swap.h"
#include <stdio.h>

t_ops	*ft_ops_ch(t_ops *ops)
{
	t_ops	*begin;

	begin = ops;
	ops = ft_last_op(ops);
	if (ft_strcmp(ops->op, "ss") == 0)
	{	
		ops->op[1] = 'a';
		begin = ft_ops(begin, "sb", 'x');
	}
	else if (ft_strcmp(ops->op, "rr") == 0)
	{	
		ops->op[1] = 'a';
		begin = ft_ops(begin, "rb", 'x');
	}
	else if (ft_strcmp(ops->op, "rrr") == 0)
	{	
		ops->op[2] = 'a';
		begin = ft_ops(begin, "rrb", 'x');
	}
	return (begin);
}

t_ops	*ft_ops(t_ops *ops, char *str, char call)
{
	t_ops	*begin;
	
	if (ops == NULL)
	{
		begin = malloc(sizeof(t_ops));
		begin->op = ft_strdup(str);
		begin->next = NULL;
	}
	else
	{
		begin = ops;
		ops = ft_last_op(ops);
		ops->next = malloc(sizeof(t_ops));
		ops = ops->next;
		ops->op = ft_strdup(str);
		ops->next = NULL;
	}
	return (call == 'c' ? ft_ops_ch(begin) : begin);
}

int	ft_isop(char *str)
{
	int	op;

	op = 0;
	op = !ft_strcmp(str, "sa") ? op + 1 : op;
	op = !ft_strcmp(str, "sb") ? op + 1 : op;
	op = !ft_strcmp(str, "ss") ? op + 1 : op;
	op = !ft_strcmp(str, "pa") ? op + 1 : op;
	op = !ft_strcmp(str, "pb") ? op + 1 : op;
	op = !ft_strcmp(str, "ra") ? op + 1 : op;
	op = !ft_strcmp(str, "rb") ? op + 1 : op;
	op = !ft_strcmp(str, "rr") ? op + 1 : op;
	op = !ft_strcmp(str, "rra") ? op + 1 : op;
	op = !ft_strcmp(str, "rrb") ? op + 1 : op;
	op = !ft_strcmp(str, "rrr") ? op + 1 : op;
	return (op);
}
