/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 12:27:48 by rklein            #+#    #+#             */
/*   Updated: 2020/06/11 11:37:21 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_isint(char **av)
{
	int				i;
	int				j;
	int				neg;
	long long int	num;

	i = -1;
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
		if (num * neg < -2147483648 || num * neg > 2147483647)
			return (0);
	}
	return (1);
}

static int	ft_numcmp(const char *s1, const char *s2)
{
	if (*s1 == '+')
		s1++;
	if (*s2 == '+')
		s2++;
	while (*s1 == *s2)
	{
		if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int			ft_valid_num(char **av)
{
	int	i;
	int	j;
	int	k;

	i = -1;
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
			if (ft_numcmp(av[i], av[k]) == 0)
				return (0);
		}
	}
	return (ft_isint(av));
}

int			ft_validator(char **par)
{
	if (!ft_valid_num(par))
	{
		ft_putendl("Error");
		return (0);
	}
	return (1);
}
