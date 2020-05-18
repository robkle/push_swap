#include "push_swap.h"
#include <stdio.h>

static void   ft_rrot(t_nums **stack)
{
	t_nums	*begin;
	t_nums	*last;
	t_nums	*new;
	t_nums	*term;
	t_nums	*tmp;

	last = ft_last_link(*stack);
	term = (*stack)->next;
	new = malloc(sizeof(t_nums));
	begin = new;
	new->num = last->num;
	while (term)
	{
		new->next = malloc(sizeof(t_nums));
		new = new->next;
		new->num = (*stack)->num;
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
		term = term->next;
	}
	new->next = NULL;
	free (tmp);
	*stack = begin;          
}

static void	ft_rot(t_nums **stack)    
{
	t_nums	*begin;
	t_nums	*start;
	t_nums	*tmp;
	
	begin = *stack;
	start = (*stack)->next;
	tmp = (*stack)->next;
	while (tmp)
	{
		tmp = tmp->next;
		*stack = (*stack)->next;
        }
	(*stack)->next = malloc(sizeof(t_nums));
	(*stack)->next->num = begin->num;
	(*stack)->next->next = NULL;
	free (begin);
	*stack = start;
}

static void	ft_swap(t_nums *stack)
{
	int	tmp;
	
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	ft_checker(t_nums **st_a, t_ops *ops)
{
	t_nums	*st_b;
	
	st_b = NULL;
	while (ops)
	{
		if (!ft_strcmp(ops->op, "sa") && *st_a && (*st_a)->next)
			ft_swap(*st_a);
		else if(!ft_strcmp(ops->op, "sb") && st_b && st_b->next)
			ft_swap(st_b);
		else if (!ft_strcmp(ops->op, "pb") && *st_a)
			st_b = ft_push(st_a, st_b);
		else if (!ft_strcmp(ops->op, "pa") && st_b)
			*st_a = ft_push(&st_b, *st_a);
		else if (!ft_strcmp(ops->op, "ra") && *st_a && (*st_a)->next)
			ft_rot(st_a);
		else if (!ft_strcmp(ops->op, "rb") && st_b && st_b->next)
			ft_rot(&st_b);
		else if (!ft_strcmp(ops->op, "rra") && *st_a && (*st_a)->next)
			ft_rrot(st_a);
		else if (!ft_strcmp(ops->op, "rrb") && st_b && st_b->next)
			ft_rrot(&st_b);
		ops = ops->next;
	}
	(ft_order(*st_a) && !st_b) ? ft_putendl("OK") : ft_putendl("KO");
	ft_free(*st_a, st_b, ops);
}	
