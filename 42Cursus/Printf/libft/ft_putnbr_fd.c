/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:49:40 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/10/09 20:12:40 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long long int n, int fd)
{
	char	aux;
	int		num;
	int		ret;

	ret = 0;
	num = 0;
	if (n == LLONG_MIN)
	{
		if (write(fd, "-9223372036854775808", 21) == -1)
			return (-1);
		return (21);
	}
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		n = -n;
		num = 1;
	}
	aux = n % 10 + '0';
	if (n >= 10)
		ret = ft_putnbr_fd(n / 10, fd);
	if (ret == -1 || write(fd, &aux, 1) == -1)
		return (-1);
	return (num + 1 + ret);
}
