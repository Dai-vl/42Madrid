/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:02:33 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/17 16:02:34 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "things.h"

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

int	ft_todec(char *str)
{
	int	num;

	num = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (num == 0)
			num = *str - '0';
		else
		{
			num *= 10;
			num += *str - '0';
		}
		++str;
	}
	return (num);
}

int	space(char *str)
{
	return (*str == ' ' || *str == '\f' || *str == '\r' || *str == '\t'
		|| *str == '\v' );
}

int	ft_atoi(char *str)
{
	int	pos;
	int	num;

	num = 0;
	while (*str != '\0' && space(str))
		++str;
	pos = 1;
	while (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			pos = -pos;
		++str;
	}
	num = ft_todec(str);
	return (num * pos);
}
