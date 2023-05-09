/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:36:01 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 16:13:00 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 0);
	exit(1);
}

int	ft_atoi_ps(const char *str)
{
	long	out;
	int		m;

	out = 0;
	m = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
	{
		m *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		out = out * 10 + *str - 48;
		if (out > INT_MAX)
			ft_error();
		str++;
	}
	if (*str != '\0')
		ft_error();
	return (out * m);
}

void	ft_check_duplicate(t_rlist *list)
{
	t_rlist	*tmpi;
	t_rlist	*tmpj;
	int		i;
	int		j;

	tmpi = list;
	i = 0;
	while (tmpi)
	{
		tmpj = list;
		j = 0;
		while (tmpj)
		{
			if (i != j && tmpi->data == tmpj->data)
				ft_error();
			tmpj = tmpj->next;
			j++;
		}
		tmpi = tmpi->next;
		i++;
	}
}

int	ft_is_sorted(t_rlist *list)
{
	while (list->next)
	{
		if (list->next->data < list->data)
			return (0);
		list = list->next;
	}
	return (1);
}
