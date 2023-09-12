typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

int ascending(int a, int b)
{
	return (a <= b);
}

int 	count_nodes(t_list *lst)
{
	int c = 0;
	t_list *p;

	p = lst;
	while (p != 0)
	{
		++c;
		p = p->next;
	}
	return c;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *i;
	t_list *j;
	int 	count = count_nodes(lst);
	int id;
	int jd;

	i = lst;
	id = 0;
	while (id < count)
	{
		j = lst;
		jd = 0;
		while (jd < count - id - 1)
		{
			if ((*cmp)(j->data, j->next->data) != 0)
			{
				int temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
			j = j->next;
			++jd;
		}
		i = i->next;
		++id;
	}
	return (lst);
}
#include <stdio.h>
int main()
{
	t_list list;
	list.data = 5;
	list.next = &(t_list){4, &(t_list){3, &(t_list){2, &(t_list){1, &(t_list){0, 0}}}}};
	t_list *aux = sort_list(&list, ascending);
	printf("%d\n", aux->data);
	printf("%d\n", aux->next->data);
	printf("%d\n", aux->next->next->data);
	printf("%d\n", aux->next->next->next->data);
	printf("%d\n", aux->next->next->next->next->data);
	printf("%d\n", aux->next->next->next->next->next->data);
	return (0);
}