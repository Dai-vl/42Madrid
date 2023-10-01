/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:49:40 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/10/01 16:18:06 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long long int n, int fd)
{
	char	aux;

	if (n == LLONG_MIN)
	{
		write(fd, "-9223372036854775808", 21);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		aux = n + '0';
		write(fd, &aux, 1);
		return ;
	}
	aux = n % 10 + '0';
	ft_putnbr_fd(n / 10, fd);
	write(fd, &aux, 1);
}
