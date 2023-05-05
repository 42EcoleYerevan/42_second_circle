#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_rlist
{
	struct s_rlist	*next;
	struct s_rlist	*prev;
	int				index;
	int				data;
} t_rlist;

void sa(t_rlist **a);
void sb(t_rlist **b);
void ss(t_rlist **a, t_rlist **b);

void pa(t_rlist **a, t_rlist **b);
void pb(t_rlist **a, t_rlist **b);

void ra(t_rlist **a);
void rb(t_rlist **b);
void rr(t_rlist **a, t_rlist **b);

void rra(t_rlist **a);
void rrb(t_rlist **b);
void rrr(t_rlist **a, t_rlist **b);

t_rlist *ft_lstnew_ps(int data);
t_rlist	*ft_lstlast_ps(t_rlist *list);
void	ft_lstadd_back_ps(t_rlist **list, t_rlist *new);
int		ft_lstlen_ps(t_rlist *list);

#endif
