/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:08:21 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/23 20:08:23 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*ret;
	int		i;
	int		index;

	ret = 0;
	if (min >= max)
		return (ret);
	ret = malloc((max - min) * sizeof(int));
	i = min;
	index = 0;
	while (i < max)
	{
		ret[index] = i;
		++i;
		++index;
	}
	return (ret);
}

/*#include <stdio.h>
int main()
{
	int *aux = ft_range(-3, -3);
	if (aux == 0)
		printf("vacio\n");
	else
	{
		int i = 0;
		while (i < 10)
		{
			printf("%d ", aux[i]);
			++i;
		}
	}
	return (0);
}*/