/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:39:16 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 17:51:02 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rra(t_rlist **a)
{
	t_rlist	*tmp;

	if (*a)
	{
		tmp = ft_lstlast_ps(*a);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *a;
		(*a)->prev = tmp;
		*a = tmp;
	}
}

void	rrb(t_rlist **b)
{
	t_rlist	*tmp;

	if (*b && (*b)->next)
	{
		tmp = ft_lstlast_ps(*b);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *b;
		(*b)->prev = tmp;
		*b = tmp;
	}
}

void	rrr(t_rlist **a, t_rlist **b)
{
	if (*a)
		rra(a);
	if (*b)
		rrb(b);
}

void	ra(t_rlist **a)
{
	t_rlist	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		tmp->prev = ft_lstlast_ps(*a);
		tmp->next = NULL;
		tmp->prev->next = tmp;
	}
}

void	rb(t_rlist **b)
{
	t_rlist	*tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		(*b)->prev = NULL;
		tmp->prev = ft_lstlast_ps(*b);
		tmp->next = NULL;
		tmp->prev->next = tmp;
	}
}
