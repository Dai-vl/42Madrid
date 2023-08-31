/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:02:41 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/21 17:02:43 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num = nb;
	while (power > 1)
	{
		num *= nb;
		--power;
	}
	return (num);
}

/*#include <stdio.h>
int main()
{
	printf("%d", ft_iterative_power(0, 0));
	return (0);
}*/