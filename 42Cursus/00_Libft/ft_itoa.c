/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:25:28 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/12 21:29:25 by dvidal-l         ###   ########.fr       */
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
	char	aux;

	j = ft_strlen(str);
	--j;
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
	return (str);
}

char	*ft_itoa(int n)
{
	char	*ret;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ret = malloc(count_memory(n) * sizeof(char));
	if (n < 0)
	{
		ret[0] = '-';
		to_char(-n, ret, 1);
	}
	else
		to_char(n, ret, 0);
	return (ft_strrev(ret));
}
