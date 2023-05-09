/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:31:32 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 18:44:18 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./get_next_line.h"
#include <stdio.h>

void	ft_parse_input(int argc, char **argv, t_rlist **list)
{
	int		i;
	char	**arr;
	char	**tmp;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			arr = ft_split(argv[i], ' ');
			tmp = arr;
			while (*arr)
			{
				ft_lstadd_back_ps(list, ft_lstnew_ps(ft_atoi_ps(*arr)));
				free(*arr);
				arr++;
			}
			i++;
			free(tmp);
		}
	}
}

void	ft_function_i_wrote(t_rlist **a, t_rlist **b)
{
	int	len;
	int	max;

	len = ft_lstlen_ps(*b);
	max = len - 1;
	while (len > 0)
	{
		while ((*b)->index != max)
		{
			if (ft_find_max(*b) == 1)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
		max--;
		len--;
	}
}

void	ft_isvalid_args(int argc, char **argv)
{
	int	n;
	int	d;
	int	i;

	n = 1;
	while (n < argc)
	{
		if (argv[n][0] == 0)
			ft_error();
		i = 0;
		d = 0;
		while (argv[n][i])
		{
			if (argv[n][i] != '-' && argv[n][i] != ' ' \
				&& ft_isdigit(argv[n][i]) == 0)
				ft_error();
			if (ft_isdigit(argv[n][i]) == 1)
				d = 1;
			i++;
		}
		if (d != 1)
			ft_error();
		n++;
	}
}

int	main(int argc, char **argv)
{
	t_rlist	*a;
	t_rlist	*b;

	b = NULL;
	ft_parse_input(argc, argv, &a);
	ft_check_duplicate(a);
	ft_isvalid_args(argc, argv);
	if (ft_is_sorted(a) == 1)
		ft_error();
	ft_sort_a(a);
	ft_input(a, b);
	if (ft_lstlen_ps(b) == 0)
	{
		if (ft_is_sorted(a) == 1)
		{
			ft_putstr_fd("OK\n", 1);
			return (0);
		}
	}
	ft_putstr_fd("KO\n", 1);
	return (0);
}
