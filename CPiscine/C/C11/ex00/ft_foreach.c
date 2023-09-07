/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:55:41 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/30 23:55:42 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		++i;
	}
}

/*#include <unistd.h>
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

int main()
{
	int tab[] = {4,56,324,34,1,234,5,2,1,3,5,2,34,5};
	ft_foreach(tab, sizeof(tab) / sizeof(tab[0]), &ft_putnbr);
}*/