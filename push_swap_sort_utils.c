#include "push_swap.h"

static int ft_sqrt(int n)
{
	int i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int ft_hitraya_funcciya(t_rlist *list)
{
	int len;

	len = ft_lstlen_ps(list);
	return (ft_sqrt(len * 2));
}

int ft_find_max(t_rlist *list)
{
	int max;
	t_rlist *tmp;

	max = ft_lstlen_ps(list) - 1;
	tmp = list;
	while (tmp->index != 0)
	{
		if (tmp->index == max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
