/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:07:18 by rklein            #+#    #+#             */
/*   Updated: 2020/08/10 10:15:47 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_nums
{
	int				num;
	struct s_nums	*next;
}				t_nums;

typedef	struct	s_ops
{
	char			*op;
	struct s_ops	*next;
}				t_ops;

char			**ft_parcpy(int ac, char **av);
int				ft_validator(char **par);
t_nums			*ft_make_list(char **par);
int				ft_valid_num(char **av);
int				ft_isop(char *str);
void			ft_presort(t_nums *stack, int *qrt);
void			ft_push_swap_a(t_nums **st_a);
void			ft_ps_long_a(t_nums **st_a, int *qrt);
void			ft_ps_rest_long(t_nums ***st_a, t_nums **st_b, t_ops **ops,
		int *qrt);
void			ft_rotate_down_b(t_nums ***st_b, t_ops **ops, int split);
t_nums			*ft_last_link(t_nums *lst);
t_ops			*ft_last_op(t_ops *lst);
int				ft_order(t_nums *stack);
void			ft_checker(t_nums **st_a, t_ops *ops);
t_ops			*ft_swap_ops(t_nums *stack, t_ops *ops, char *str);
t_ops			*ft_ops(t_ops *ops, char *str, char call);
t_nums			*ft_push(t_nums **src, t_nums *dst);
t_ops			*ft_rot_ops(t_nums ***stack, t_ops *ops, char *str);
t_ops			*ft_rrot_ops(t_nums ***stack, t_nums *last,
								t_ops *ops, char *str);
void			ft_sort_b(t_nums **st, t_ops **ops);
void			ft_push_b(t_nums **st_a, t_nums **st_b, t_ops **ops);
void			ft_print_ops(t_ops *ops);
void			ft_free(t_nums *st_a, t_nums *st_b, t_ops *ops);

#endif
