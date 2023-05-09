/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:39:48 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 14:42:06 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_rlist
{
	struct s_rlist	*next;
	struct s_rlist	*prev;
	int				index;
	int				data;
}	t_rlist;

void	sa(t_rlist **a);
void	sb(t_rlist **b);
void	ss(t_rlist **a, t_rlist **b);

void	pa(t_rlist **a, t_rlist **b);
void	pb(t_rlist **a, t_rlist **b);

void	ra(t_rlist **a);
void	rb(t_rlist **b);
void	rr(t_rlist **a, t_rlist **b);

void	rra(t_rlist **a);
void	rrb(t_rlist **b);
void	rrr(t_rlist **a, t_rlist **b);

t_rlist	*ft_lstnew_ps(int data);
t_rlist	*ft_lstlast_ps(t_rlist *list);
void	ft_lstadd_back_ps(t_rlist **list, t_rlist *new);
int		ft_lstlen_ps(t_rlist *list);

void	ft_error(void);
int		ft_atoi_ps(const char *str);
void	ft_check_duplicate(t_rlist *list);
int		ft_is_sorted(t_rlist *list);

void	ft_push_a(t_rlist **a, t_rlist **b);
void	batterfly(t_rlist **a, t_rlist **b, int lambda);
void	ft_sort_a(t_rlist *a);
void	ft_set_index(t_rlist *a, int index);

int		ft_hitraya_funcciya(t_rlist *list);
int		ft_find_max(t_rlist *list);

void	ft_sort_3_numbers(t_rlist **a);
void	ft_sort_4_numbers(t_rlist **a, t_rlist **b);
void	ft_sort_5_numbers(t_rlist **a, t_rlist **b);

#endif
