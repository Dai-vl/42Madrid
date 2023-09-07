/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:15:09 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/31 00:15:10 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ord;

	i = 0;
	ord = 1;
	while (i < length - 1 && ord)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			ord = 0;
		++i;
	}
	i = 0;
	if (!ord)
	{
		ord = 1;
		while (i < length - 1)
		{
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
			++i;
		}
	}
	return (1);
}
