#include "push_swap.h"

static void	ft_quartiles(int *nums, int *qrt)
{
	qrt[1] = nums[(qrt[0] / 2) - 1];
	qrt[2] = nums[(qrt[0] / 4) - 1];
	qrt[3] = nums[(qrt[0] / 2 + qrt[0] / 4) - 1];
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

void	ft_presort(t_nums *stack, int *qrt)
{
	int	*nums;

	qrt[0] = ft_numcount(stack);
	nums = ft_numarr(stack, qrt[0]);
	ft_quartiles(nums, qrt);
	free(nums);
}
