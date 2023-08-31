/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:40:51 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/17 14:40:52 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	aux;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
	{
		aux = nb + '0';
		write(1, &aux, 1);
		return ;
	}
	aux = nb % 10 + '0';
	ft_putnbr(nb / 10);
	write(1, &aux, 1);
}

/*int main()
{
	ft_putnbr(-2147483648);
	return 0;
}*/