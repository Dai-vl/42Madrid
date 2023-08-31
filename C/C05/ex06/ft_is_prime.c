/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:16:34 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/21 20:16:36 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		++i;
	}
	return (1);
}

/*#include <stdio.h>
int main()
{
	int i = 0;

	while (i < 1000)
	{
		if(ft_is_prime(i))
			printf("%d ", i);
		++i;
	}
}*/