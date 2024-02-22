/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:41:35 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/28 12:41:36 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		num;

	num = 0;
	while (*str != '\0')
	{
		++num;
		++str;
	}
	return (num);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	while (src[i])
		++i;
	ret = malloc((i + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	i = 0;
	while (*src)
	{
		ret[i] = *src;
		++i;
		++src;
	}
	ret[i] = '\0';
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			i;

	i = 0;
	stock = malloc((ac + 1) * sizeof(t_stock_str));
	if (stock == 0)
		return (0);
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = ft_strdup(av[i]);
		if (stock[i].str == 0)
			return (0);
		stock[i].copy = ft_strdup(stock[i].str);
		if (stock[i].copy == 0)
			return (0);
		++i;
	}
	stock[i].str = 0;
	return (stock);
}
