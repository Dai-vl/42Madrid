#include "libft.h"
#include <stdio.h>
void ft_lstprint(void *content)
{
	ft_putendl_fd((char *)content, 1);
}

void *ft_lstprint2(void *content)
{
	ft_putendl_fd((char *)content, 1);
	return (0);
}

int main()
{
	t_list *list;
	
	list = (t_list *) malloc(sizeof(t_list));

	//test ft_lstnew
	ft_lstadd_front(&list, ft_lstnew("Hola"));

	//test ft_lstadd_back
	ft_lstadd_back(&list, ft_lstnew("Adios"));

	//test ft_lstsize
	printf("size: %d\n", ft_lstsize(list));

	//test ft_lstlast
	printf("last: %s\n", (char *)ft_lstlast(list)->content);

	//test ft_lstiter
	ft_lstiter(list, &ft_lstprint);

	//test ft_lstmap
	ft_lstmap(list, &ft_lstprint2, &ft_lstprint);

	return (0);
}

// compile -o main main.c -L. -lft
