/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:29:21 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/23 20:29:22 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		index;
	int		*array;

	*range = 0;
	if (min >= max)
		return (0);
	array = malloc((max - min) * sizeof(int));
	if (array == 0)
		return (-1);
	*range = array;
	i = min;
	index = 0;
	while (i < max)
	{
		array[index] = i;
		++i;
		++index;
	}
	return (index);
}

/*#include <stdio.h>
int main()
{
	int *range;
	int aux = ft_ultimate_range(&range, -3, 7);
	printf("%d\n", aux);
	if (aux == 0)
		printf("vacio\n");
	else
	{
		int i = 0;
		while (i < 10)
		{
			printf("%d ", range[i]);
			++i;
		}
	}
	return (0);
}*/