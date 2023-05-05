#include "./push_swap.h"


void ft_error()
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
	if (*str !='\0')
		ft_error();
	return (out * m);
}

void  ft_check_duplicate(t_rlist *list)
{
	t_rlist *tmpi;
	t_rlist *tmpj;
	int i;
	int j;

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

void	ft_parse_input(int argc, char **argv, t_rlist **list)
{
	int i;
	char **arr;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			arr = ft_split(argv[i], ' ');
			while (*arr)
			{
				ft_lstadd_back_ps(list, ft_lstnew_ps(ft_atoi_ps(*arr)));
				arr++;
			}
			i++;
		}
	}
}

void ft_printf_list(t_rlist *list, char c)
{
	printf("%c: ", c);
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	puts("");
}

int ft_is_sorted(t_rlist *list)
{
	while (list->next)
	{
		if (list->next->data < list->data)
			return (0);
		list = list->next;
	}
	return (1);
}

static void ft_set_index(t_rlist *a, int index)
{
	t_rlist *max;

	max = a;
	while (max->index != -1)
		max = max->next;
	while (a)
	{
		if (a->index == -1 && a->data > max->data)
			max = a;
		a = a->next;
	}
	max->index = index;
}

void ft_sort_a(t_rlist *a)
{
	int index;

	index = ft_lstlen_ps(a) - 1;
	while (index >= 0)
	{
		ft_set_index(a, index);
		index--;
	}

}

void batterfly(t_rlist **a, t_rlist **b)
{
	int len;
	int n;

	len = ft_lstlen_ps(*a);
	n = 0;
	while (n < len)
	{
		if ((*a)->index <= n)
		{
			pb(a, b);
			rb(b);
			n++;
		}
		else if ((*a)->index <= n + 1)
		{
			pb(a, b);
			n++;
		}
		else
			ra(a);
	}
}

void ft_push_a(t_rlist **a, t_rlist **b)
{
	int len;
	t_rlist *tmp;

	len = ft_lstlen_ps(*b) - 1;
	while (len >= 0)
	{
		tmp = ft_lstlast_ps(*b);
		if (tmp->index > (*b)->index)
		{
			rrb(b);
			pa(a, b);
		}
		else
		{
			pa(a, b);
		}
		len--;
	}
}

int main(int argc, char **argv)
{
	t_rlist *a;
	t_rlist *b;

	b = NULL;
	ft_parse_input(argc, argv, &a);
	ft_check_duplicate(a);
	if (ft_is_sorted(a) == 1)
		ft_error();
	ft_sort_a(a);
	batterfly(&a, &b);
	ft_push_a(&a, &b);
	/* pb(&a, &b); */
	/* pb(&a, &b); */
	/* pb(&a, &b); */
	/* pb(&a, &b); */
	/* pb(&a, &b); */
	/* pb(&a, &b); */
	/* puts(""); */
	/* pa(&a, &b); */
	/* pa(&a, &b); */
	/* pa(&a, &b); */
	/* pa(&a, &b); */
	/* pa(&a, &b); */
	/* pa(&a, &b); */
	/* puts(""); */
	/* ft_printf_list(a, 'a'); */
	/* puts(""); */
	/* ft_printf_list(b, 'b'); */

	return (0);
}
