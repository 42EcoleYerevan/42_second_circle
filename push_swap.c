#include "./push_swap.h"

/* static void ft_lstprint(void *content) */
/* { */
/* 	printf("%d\n", *(int *)content); */
/* } */

/* t_list *set_list(int argc, char **argv) */
/* { */
/* 	int n; */
/* 	int integer; */
/* 	char **arr; */
/* 	t_list *list; */

/* 	list = NULL; */
/* 	if (argc > 1) */
/* 	{ */
/* 		n = 1; */
/* 		while (n < argc) */
/* 		{ */
/* 			arr = ft_split(argv[n], ' '); */
/* 			n++; */
/* 			while (*arr) */
/* 			{ */
/* 				integer = ft_atoi(*arr); */
/* 				printf("%s %d\n", *arr, integer); */
/* 				ft_lstadd_back(&list, ft_lstnew(&integer)); */
/* 				printf("%d\n", *(int *)list->content); */
/* 				arr++; */
/* 			} */
/* 		} */
/* 	} */
/* 	return (list); */
/* } */

int main()
{
	/* t_list *list; */

	/* list = set_list(argc, argv); */
	/* ft_lstiter(list, ft_lstprint); */
	/* printf("%d\n", *(int *)list->content); */ 
	/* printf("%d\n", *(int *)(list->next->content)); */ 
	/* printf("%d\n", *(int *)(list->next->next->content)); */ 

	/* int a = 1; */
	/* t_list *list1; */
	/* t_list *tmp; */
	/* for (int i = 0; i < 4; i++) */
	/* { */
	/* 	/1* ft_lstadd_back(&list1, ft_lstnew(&a)); *1/ */
	/* 	if (list1 == NULL) */
	/* 	{ */
	/* 		list1 = ft_lstnew(&a); */
	/* 		tmp = list1; */
	/* 	} */
	/* 	else */
	/* 	{ */
	/* 		tmp->next = ft_lstnew(&a); */
	/* 		tmp = tmp->next; */
	/* 		/1* list1->next = ft_lstnew(&a); *1/ */
	/* 		/1* list1 = list1->next; *1/ */
	/* 	} */
	/* 	a = i; */
	/* } */
	/* printf("%d\n", *(int *)list1->content); */
	/* for (int i = 0; i < 4; i++) */
	/* { */
	/* 	/1* printf("%d\n", *(int *)list1->content); *1/ */
	/* 	list1 = list1->next; */
	/* } */

	int b;
	t_list *a;
	/* t_list *c; */
	/* c = ft_lstnew(&b); */

	b = 1;
	a = ft_lstnew(&b);
	ft_lstadd_back(&a, ft_lstnew(&(12)));

	/* b = 1; */
	/* a = ft_lstnew(&b); */
	/* b = 2; */
	/* ft_lstlast(a)->next = ft_lstnew(&b); */
	/* b = 3; */
	/* ft_lstlast(a)->next = ft_lstnew(&b); */
	/* a->next = ft_lstnew(&b); */
	/* b = 3; */
	/* a->next->next = ft_lstnew(&b); */

	printf("%d\n", *(int *)a->content);
	/* printf("%d\n", *(int *)a->next->content); */
	/* printf("%d\n", *(int *)a->next->next->content); */
	/* printf("%d\n", *(int *)a->next->next->next->content); */
	return (0);
}
