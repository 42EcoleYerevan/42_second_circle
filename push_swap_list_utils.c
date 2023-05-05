#include "push_swap.h"

t_rlist *ft_lstnew_ps(int data)
{
	t_rlist *new;
	new = (t_rlist *)malloc(sizeof(t_rlist));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = -1;
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
