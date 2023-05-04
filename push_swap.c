#include "./push_swap.h"

typedef struct s_rlist
{
	struct s_rlist	*next;
	struct s_rlist	*prev;
	int		data;
} t_rlist;

t_rlist *ft_lstnew_ps(int data)
{
	t_rlist *new;
	new = (t_rlist *)malloc(sizeof(t_rlist));
	if (!new)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_rlist *ft_lstlast_ps(t_rlist *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_lstadd_back_ps(t_rlist **list, t_rlist *new)
{
	t_rlist *tmp;

	if (*list)
	{

		tmp = ft_lstlast_ps(*list);
		tmp->next = new;
		new->prev = tmp;
	}
	else
		*list = new;
}

int ft_lstlen_ps(t_rlist *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

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
				ft_lstadd_back_ps(list, ft_lstnew_ps(ft_atoi(*arr)));
				arr++;
			}
			i++;
		}
	}
}

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
		tmp->next = *a;
		(*a)->prev = tmp;
		*a = tmp;
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
		tmp->next = *b;
		(*b)->prev = tmp;
		*b = tmp;
		ft_putstr_fd("pb\n", 1);
	}
}

void ra(t_rlist **a)
{
	t_rlist *tmp;

	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->prev = ft_lstlast_ps(*a);
	tmp->next = NULL;
	tmp->prev->next = tmp;
	ft_putstr_fd("ra\n", 1);
}

void rb(t_rlist **b)
{
	t_rlist *tmp;

	tmp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->prev = ft_lstlast_ps(*b);
	tmp->next = NULL;
	tmp->prev->next = tmp;
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
		*a = tmp;
		ft_putstr_fd("rra\n", 1);
	}
}

void rrb(t_rlist **b)
{
	t_rlist *tmp;

	if (*b)
	{
		tmp = ft_lstlast_ps(*b);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *b;
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

int main(int argc, char **argv)
{
	t_rlist *a;
	t_rlist *b;

	a = NULL;
	ft_parse_input(argc, argv, &b);
	ft_check_duplicate(b);
	

	while (a)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
	puts("");
	while (b)
	{
		printf("%d\n", b->data);
		b = b->next;
	}
	return (0);
}
