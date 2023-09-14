#include "Libft/libft.h"
#include <stdio.h>

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

	return (0);
}

// compile -o main main.c -L. -lft
