/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:01:59 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/31 00:02:00 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret;

	i = 0;
	ret = malloc(length * sizeof(int));
	if (ret == 0)
		return (ret);
	while (i < length)
	{
		ret[i] = (*f)(tab[i]);
		++i;
	}
	return (ret);
}
