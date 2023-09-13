/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:25:28 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/13 20:53:41 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_memory(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		++count;
		n = -n;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count + 1);
}

static void	to_char(int n, char *ret, int i)
{
	if (n <= 9)
		ret[i] = n + '0';
	else
	{
		ret[i] = (n % 10) + '0';
		to_char(n / 10, ret, i + 1);
	}
}

static char	*ft_strrev(char *str)
{
	int		j;
	int		i;
	int		size;
	char	aux;

	size = ft_strlen(str);
	j = size - 1;
	i = 0;
	if (str[i] == '-')
		++i;
	while (i < j)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		++i;
		--j;
	}
	str[size] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_memory(n);
	ret = malloc(size * sizeof(char));
	if (!ret)
		return (0);
	if (n < 0)
	{
		ret[0] = '-';
		to_char(-n, ret, 1);
	}
	else
		to_char(n, ret, 0);
	ret[size - 1] = '\0';
	return (ft_strrev(ret));
}
