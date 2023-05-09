/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:39:21 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 14:39:31 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pa(t_rlist **a, t_rlist **b)
{
	t_rlist	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		if (*a)
		{
			(*a)->prev = tmp;
			tmp->next = *a;
			*a = tmp;
		}
		else
		{
			*a = tmp;
			(*a)->next = NULL;
		}
		if (*b)
			(*b)->prev = NULL;
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_rlist **a, t_rlist **b)
{
	t_rlist	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		if (*b)
		{
			(*b)->prev = tmp;
			tmp->next = *b;
			*b = tmp;
		}
		else
		{
			*b = tmp;
			(*b)->next = NULL;
		}
		if (*a)
			(*a)->prev = NULL;
	}
	ft_putstr_fd("pb\n", 1);
}

void	sa(t_rlist **a)
{
	t_rlist	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	tmp->prev = *a;
	(*a)->next = tmp;
	(*a)->prev = NULL;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_rlist **b)
{
	t_rlist	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	tmp->prev = *b;
	(*b)->next = tmp;
	(*b)->prev = NULL;
	ft_putstr_fd("sb\n", 1);
}
