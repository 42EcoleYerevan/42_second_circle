/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:31:32 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 20:23:27 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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
	else
		exit(0);
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
	int		lambda;
	t_rlist	*a;
	t_rlist	*b;

	ft_parse_input(argc, argv, &a);
	ft_check_duplicate(a);
	ft_isvalid_args(argc, argv);
	if (ft_is_sorted(a) == 1)
		exit(0);
	ft_sort_a(a);
	if (ft_lstlen_ps(a) == 3)
		ft_sort_3_numbers(&a);
	else if (ft_lstlen_ps(a) == 4)
		ft_sort_4_numbers(&a, &b);
	else if (ft_lstlen_ps(a) == 5)
		ft_sort_5_numbers(&a, &b);
	else if (ft_lstlen_ps(a) == 2)
		sa(&a);
	else
	{
		lambda = ft_hitraya_funcciya(a);
		batterfly(&a, &b, lambda);
		ft_function_i_wrote(&a, &b);
	}
}
