#include "push_swap.h"

void ft_set_index(t_rlist *a, int index)
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

void batterfly(t_rlist **a, t_rlist **b, int lambda)
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
		else if ((*a)->index <= n + lambda)
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
