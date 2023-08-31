/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:26:52 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/21 17:26:53 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	ini;
	int	fin;
	int	ret;

	if (nb == 1)
		return (1);
	ini = 1;
	fin = nb / 2;
	while (ini <= fin)
	{
		ret = (ini + fin) / 2;
		if (nb / ret == ret && nb % ret == 0)
			return (ret);
		if (ret < nb / ret)
			ini = ret + 1;
		else
			fin = ret - 1;
	}
	return (0);
}

/*#include <stdio.h>
int main()
{
	printf("%d", ft_sqrt(25));
	return (0);
}*/