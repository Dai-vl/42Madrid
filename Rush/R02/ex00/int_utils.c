/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:35:36 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/27 17:35:38 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(char *str, unsigned int *num)
{
	*num = 0;
	while (*str != '\0' && (*str == ' ' || (*str >= 9 && *str <= 13)))
		++str;
	if (*str != '\0' && (*str == '-' || *str == '+'))
		return (FAIL);
	while (*str && *str >= '0' && *str <= '9')
	{
		if (*num == 0)
			*num = *str - '0';
		else
		{
			*num *= 10;
			*num += *str - '0';
		}
		++str;
	}
	if (*str && (*str < '0' || *str > '9'))
		return (FAIL);
	return (SUCCESS);
}

int	ft_power(unsigned int nb, int power)
{
	unsigned int	num;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num = nb;
	while (power > 1)
	{
		num *= nb;
		--power;
	}
	return (num);
}

int	check_repeated(t_map *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab->map_arr[i].key == tab->map_arr[i + 1].key)
			return (FAIL);
		++i;
	}
	return (SUCCESS);
}
