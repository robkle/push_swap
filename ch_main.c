/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:11:01 by rklein            #+#    #+#             */
/*   Updated: 2020/06/29 09:48:16 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	char	**par;
	t_nums	*stack_a;
	char	*line;
	t_ops	*ops;

	if (argc >= 2)
	{
		par = argc == 2 ? ft_strsplit(argv[1], ' ') : ft_parcpy(argc, argv);
		if (!ft_validator(par) || !(stack_a = ft_make_list(par)))
			return (0);
		ops = NULL;
		while (get_next_line(0, &line))
		{
			if (!ft_isop(line))
			{
				ft_free(stack_a, NULL, ops);
				return (0);
			}
			ops = ft_ops(ops, line, 'c');
		}
		ft_checker(&stack_a, ops);
		ft_free(NULL, NULL, ops);
	}
	return (0);
}
