/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:52:18 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 18:52:18 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_input_2(t_rlist *a, t_rlist *b, char *arr)
{
	if (ft_strncmp(arr, "sa", 2) == 0 && ft_strlen(arr) == 3)
		sa(&a);
	else if (ft_strncmp(arr, "sb", 2) == 0 && ft_strlen(arr) == 3)
		sb(&b);
	else if (ft_strncmp(arr, "ss", 2) == 0 && ft_strlen(arr) == 3)
		ss(&a, &b);
	else if (ft_strncmp(arr, "ra", 2) == 0 && ft_strlen(arr) == 3)
		ra(&a);
	else if (ft_strncmp(arr, "rb", 2) == 0 && ft_strlen(arr) == 3)
		rb(&b);
	else if (ft_strncmp(arr, "rr", 2) == 0 && ft_strlen(arr) == 3)
		rr(&a, &b);
}

void	ft_input(t_rlist *a, t_rlist *b)
{
	char	*arr;

	while (1)
	{
		arr = get_next_line(0);
		if (!arr)
			break ;
		else if (ft_strlen(arr) == 3)
			ft_input_2(a, b, arr);
		else if (ft_strncmp(arr, "rra", 3) == 0 && ft_strlen(arr) == 4)
			rra(&a);
		else if (ft_strncmp(arr, "rrb", 3) == 0 && ft_strlen(arr) == 4)
			rrb(&b);
		else if (ft_strncmp(arr, "rrr", 3) == 0 && ft_strlen(arr) == 4)
			rrr(&a, &b);
		else
			ft_error();
		free(arr);
	}
}
