/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:34:29 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 14:39:45 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_rlist **a, t_rlist **b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_rlist **a, t_rlist **b)
{
	if (*a)
		ra(a);
	if (*b)
		rb(b);
	ft_putstr_fd("rr\n", 1);
}
