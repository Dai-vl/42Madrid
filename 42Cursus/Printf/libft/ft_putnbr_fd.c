/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:49:40 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/10/02 12:00:56 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long long int n, int fd)
{
	char	aux;
	int		num;

	num = 0;
	if (n == LLONG_MIN)
	{
		write(fd, "-9223372036854775808", 21);
		return (21);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		num = 1;
	}
	if (n < 10)
	{
		aux = n + '0';
		write(fd, &aux, 1);
		return (num + 1);
	}
	aux = n % 10 + '0';
	num += ft_putnbr_fd(n / 10, fd);
	write(fd, &aux, 1);
	return (num + 1);
}
