/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:30:51 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/10 11:26:29 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_sort_3_numbers(t_rlist **a)
{
	t_rlist	*tmp;
	int		max;

	max = -1;
	tmp = *a;
	while (tmp)
	{
		if (max < tmp->data)
			max = tmp->data;
		tmp = tmp->next;
	}
	if (max == (*a)->data)
		ra(a);
	else if (max == (*a)->next->data)
	{
		sa(a);
		ra(a);
	}
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	ft_sort_4_numbers(t_rlist **a, t_rlist **b)
{
	while ((*a)->index != 3)
	{
		if (ft_find_max(*a) == 1)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	ft_sort_3_numbers(a);
	pa(a, b);
	ra(a);
}

void	ft_sort_5_numbers(t_rlist **a, t_rlist **b)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	ft_sort_3_numbers(a);
	if ((*b)->index < (*b)->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
}
