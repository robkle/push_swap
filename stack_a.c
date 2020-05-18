#include "push_swap.h"

static int	ft_isint(char **av)
{
	int		i;
	int		j;
	int		neg;
	long long int	num;

	i = 0;
	while (av[++i])
	{
		j = 0;
		neg = av[i][j] == '-' ? -1 : 1;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		num = 0;
		while (av[i][j] >= '0' && av[i][j] <= '9')
		{
			if (j == 11)
				return (0);
			num = 10 * num + (av[i][j] - 48);
			j++;
		}
		if (num * neg  < -2147483648 || num * neg > 2147483647)
			return (0);
	}
	return (1);
}

int	ft_valid_num(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		k = i;
		while (av[++k])
		{
			if (!ft_strcmp(av[i], av[k]))
				return (0);
		}
	}
	return (ft_isint(av));
}

t_nums	*ft_make_list(int ac, char **av)
{	
	t_nums	*lst;
	t_nums	*begin;
	int	i;

	if(!(lst = (t_nums*)malloc(sizeof(t_nums))))
		return (NULL);
	begin = lst;
	i = 0;
	while (++i < ac - 1)
	{
		lst->num = ft_atoi(av[i]);
		if(!(lst->next = (t_nums*)malloc(sizeof(t_nums))))
			return (NULL);
		lst = lst->next;
	}
	lst->num = ft_atoi(av[i]);
	lst->next = NULL;
	return (begin);
}

int	ft_order(t_nums *stack)
{
	t_nums  *lst;

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

