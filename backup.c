
void	ft_push_b(t_nums **st_a, t_nums **st_b, t_ops **ops)
{
	t_nums *last_a;
	int		max;

	if (*st_b)
	{
		
		last_a = ft_last_link(*st_a);
		max = last_a->num; 
		while ((*st_b)->next)
		{
			
			/*last = ft_last_link(*st_b);
			if (last->num > qrt[3])
			{
				if (last->num > (*st_b)->num && last->num > (*st_b)->next->num)
					*ops = ft_rrot_ops(&st_b, last, *ops, "rrb");
				else if ((*st_b)->num < (*st_b)->next->num)
					*ops = ft_swap_ops(*st_b, *ops, "sb");
			}
			else if ((*st_b)->num < (*st_b)->next->num &&
						(*st_b)->num < (*st_b)->next->next->num)
				*ops = ft_rot_ops(&st_b, *ops, "rb");*/
			if ((*st_b)->num < (*st_b)->next->num)
				*ops = ft_swap_ops(*st_b, *ops, "sb");
			while ((*st_b)->num > (*st_a)->num && ((*st_a)->next &&
						((*st_b)->num > (*st_a)->next->num)))
				*ops = ft_rot_ops(&st_a, *ops, "ra");
			last_a = ft_last_link(*st_a); 
			while (last_a->num != max && last_a->num > (*st_b)->num)
			{
				*ops = ft_rrot_ops(&st_a, last_a, *ops, "rra");
				last_a = ft_last_link(*st_a);
			} 
			*st_a = ft_push(st_b, *st_a);
			*ops = ft_ops(*ops, "pa", 'p');
			if ((*st_a)->num > (*st_a)->next->num)
				*ops = ft_swap_ops(*st_a, *ops, "sa");
		}
		last_a = ft_last_link(*st_a);
		while (last_a->num > (*st_b)->num && last_a->num != max)
		{
			*ops = ft_rrot_ops(&st_a, last_a, *ops, "rra");
			last_a = ft_last_link(*st_a);
		}
		*st_a = ft_push(st_b, *st_a);
		*ops = ft_ops(*ops, "pa", 'p');
		while (last_a->num != max)
		{
			*ops = ft_rrot_ops(&st_a, last_a, *ops, "rra");
			last_a = ft_last_link(*st_a);
		}
	} 
	ft_print_ops(*ops);
	ft_free(*st_a, *st_b, *ops);
}
