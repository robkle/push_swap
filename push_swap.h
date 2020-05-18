#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_nums
{
	int		num;
	struct s_nums	*next;
}		t_nums;

typedef	struct	s_ops
{
	char		*op;
	struct s_ops	*next;
}		t_ops;

t_nums	*ft_make_list(int ac, char **av);
int	ft_valid_num(char **av);
int	ft_isop(char *str);
void    ft_push_swap_a(t_nums **st_a);
t_nums  *ft_last_link(t_nums *lst);
t_ops	*ft_last_op(t_ops *lst);
int	ft_order(t_nums *stack);
void	ft_checker(t_nums **st_a, t_ops *ops);
t_ops	*ft_swap_ops(t_nums *stack, t_ops *ops, char *str);
t_ops	*ft_ops(t_ops *ops, char *str, char call);
t_nums	*ft_push(t_nums **src, t_nums *dst);
t_ops	*ft_rot_ops(t_nums ***stack, t_ops *ops, char *str);
t_ops	*ft_rrot_ops(t_nums ***stack, t_nums *last, t_ops *ops, char *str);
void	ft_sort_b(t_nums **st, t_ops **ops);
void	ft_push_b(t_nums **st_a, t_nums **st_b, t_ops **ops);
void	ft_print_ops(t_ops *ops);
void	ft_free(t_nums *st_a, t_nums *st_b, t_ops *ops);
#endif
