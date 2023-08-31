/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:45:01 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/12 17:45:05 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *e1, int *e2)
{
	int	aux;

	aux = *e1;
	*e1 = *e2;
	*e2 = aux;
}

int	partition(int tab[], int ini, int fin)
{
	int	piv;
	int	i;
	int	j;

	piv = tab[fin];
	i = ini - 1;
	j = ini;
	while (j < fin)
	{
		if (tab[j] < piv)
		{
			++i;
			swap(&tab[j], &tab[i]);
		}
		++j;
	}
	swap(&tab[i +1], &tab[fin]);
	return (i + 1);
}

void	quicksort(int *tab, int ini, int fin)
{
	int	piv;

	if (ini >= fin)
		return ;
	piv = partition(tab, ini, fin);
	quicksort(tab, ini, piv - 1);
	quicksort(tab, piv + 1, fin);
}

void	ft_sort_int_tab(int *tab, int size)
{
	quicksort(tab, 0, size -1);
}
