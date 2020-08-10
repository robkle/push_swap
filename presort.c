/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:33:21 by rklein            #+#    #+#             */
/*   Updated: 2020/08/10 10:36:32 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_quartiles(int *nums, int *qrt)
{
	int	lt;
	int	ut;
	int	lsplit;
	int	msplit;
	int	usplit;

	lt = qrt[0] / 3;
	ut = lt * 2;
	lsplit = lt / 2;
	msplit = ut - lsplit;
	usplit = qrt[0] - lsplit;
	qrt[1] = nums[lt - 1];
	qrt[2] = nums[ut - 1];
	qrt[3] = nums[lsplit - 1];
	qrt[4] = nums[msplit - 1];
	qrt[5] = nums[usplit - 1];
}

static int	*ft_numsrt(int *nums, int size)
{
	int	i;
	int j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (nums[i] > nums[j])
			{
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
	}
	return (nums);
}

static int	*ft_numarr(t_nums *stack, int size)
{
	int	*nums;
	int	i;

	nums = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (stack)
	{
		nums[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (ft_numsrt(nums, size));
}

static int	ft_numcount(t_nums *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void		ft_presort(t_nums *stack, int *qrt)
{
	int	*nums;

	qrt[0] = ft_numcount(stack);
	nums = ft_numarr(stack, qrt[0]);
	ft_quartiles(nums, qrt);
	free(nums);
}
