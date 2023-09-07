/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:47:34 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/27 17:47:36 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swap(t_data *e1, t_data *e2)
{
	t_data	aux;

	aux = *e1;
	*e1 = *e2;
	*e2 = aux;
}

int	partition(t_data tab[], int ini, int fin)
{
	unsigned int	piv;
	int				i;
	int				j;

	piv = tab[fin].key;
	i = ini - 1;
	j = ini;
	while (j < fin)
	{
		if (tab[j].key < piv)
		{
			++i;
			swap(&tab[j], &tab[i]);
		}
		++j;
	}
	swap(&tab[i +1], &tab[fin]);
	return (i + 1);
}

void	quicksort(t_data *tab, int ini, int fin)
{
	int	piv;

	if (ini >= fin)
		return ;
	piv = partition(tab, ini, fin);
	quicksort(tab, ini, piv - 1);
	quicksort(tab, piv + 1, fin);
}

void	sort(t_data *tab, int size)
{
	quicksort(tab, 0, size -1);
}
