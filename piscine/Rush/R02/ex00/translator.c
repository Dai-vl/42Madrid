/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:43:55 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/27 17:43:57 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	put_ten_multiples(int len, t_map map)
{
	char	*to_print;

	ft_putstr(" ");
	to_print = binary_search(ft_power(10, len), map, 0, map.size);
	if (to_print == 0)
		return (FAIL);
	ft_putstr(to_print);
	return (SUCCESS);
}

int	case_zero(unsigned int num, t_map map)
{
	char	*to_print;

	to_print = binary_search(num, map, 0, map.size);
	if (to_print == 0)
		return (FAIL);
	ft_putstr(to_print);
	return (SUCCESS);
}

int	translate_number(char *number, t_map map, int len, unsigned int num)
{
	int		partitions;
	int		i;
	int		aux;

	if (num == 0)
		return (case_zero(num, map));
	partitions = (len / 3) + (len % 3 != 0);
	i = 0;
	while (i < partitions)
	{
		if (i != 0 && ft_strncmp(number, "000", 3) == 1)
			ft_putstr(" ");
		aux = translate_number_aux(number, map, len);
		len -= aux;
		if (len != 0 && ft_strncmp(number, "000", 3) == 1
			&& put_ten_multiples(len, map) == FAIL)
			return (FAIL);
		number += aux;
		++i;
	}
	ft_putstr("\n");
	return (SUCCESS);
}

int	translate_number_aux(char *number, t_map map, int len)
{
	unsigned int	i;
	unsigned int	aux;
	char			*c;

	i = 0;
	aux = len % 3;
	if (aux == 0)
		aux = 3;
	c = malloc((aux + 1) * sizeof(char));
	while (i < aux)
	{
		c[i] = *number;
		++number;
		++i;
	}
	c[i] = '\0';
	ft_atoi(c, &i);
	print_hundreds(c, map, aux, i);
	free(c);
	return (aux);
}

char	*binary_search(unsigned int num, t_map map, int ini, int end)
{
	int	mid;

	if (ini >= end)
		return (0);
	else
	{
		mid = (ini + end) / 2;
		if (map.map_arr[mid].key == num)
			return (map.map_arr[mid].value);
		if (map.map_arr[mid].key < num)
			return (binary_search(num, map, mid + 1, end));
		else
			return (binary_search(num, map, ini, mid));
	}
}
