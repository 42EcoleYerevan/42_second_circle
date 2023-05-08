#include "push_swap.h"

void sa(t_rlist **a)
{
	t_rlist *tmp;
	
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

void sb(t_rlist **b)
{
	t_rlist *tmp;
	
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

void ss(t_rlist **a, t_rlist **b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}

void pa(t_rlist **a, t_rlist **b)
{
	t_rlist *tmp;

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

void pb(t_rlist **a, t_rlist **b)
{
	t_rlist *tmp;

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

void ra(t_rlist **a)
{
	t_rlist *tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		tmp->prev = ft_lstlast_ps(*a);
		tmp->next = NULL;
		tmp->prev->next = tmp;
	}
	ft_putstr_fd("ra\n", 1);
}

void rb(t_rlist **b)
{
	t_rlist *tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		(*b)->prev = NULL;
		tmp->prev = ft_lstlast_ps(*b);
		tmp->next = NULL;
		tmp->prev->next = tmp;
	}
	ft_putstr_fd("rb\n", 1);
}

void rr(t_rlist **a, t_rlist **b)
{
	if (*a)
		ra(a);
	if (*b)
		rb(b);
	ft_putstr_fd("rr\n", 1);
}

void rra(t_rlist **a)
{
	t_rlist *tmp;

	if (*a)
	{
		tmp = ft_lstlast_ps(*a);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *a;
		(*a)->prev = tmp;
		*a = tmp;
		ft_putstr_fd("rra\n", 1);
	}
}

void rrb(t_rlist **b)
{
	t_rlist *tmp;

	if (*b && (*b)->next)
	{
		tmp = ft_lstlast_ps(*b);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *b;
		(*b)->prev = tmp;
		*b = tmp;
		ft_putstr_fd("rrb\n", 1);
	}
}

void rrr(t_rlist **a, t_rlist **b)
{
	if (*a)
		rra(a);
	if (*b)
		rrb(b);
	ft_putstr_fd("rrr\n", 1);
}
