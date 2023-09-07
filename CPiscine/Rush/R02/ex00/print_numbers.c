/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:47:14 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/27 17:47:15 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_hundreds(char *number, t_map map, int len, unsigned int num)
{
	int		aux;
	char	*to_print;

	if (num == 0)
		return ;
	if (num <= 20)
	{
		to_print = binary_search(num, map, 0, map.size);
		ft_putstr(to_print);
	}
	else if (num > 20 && num < 100)
	{
		aux = num % 10;
		to_print = binary_search(num - aux, map, 0, map.size);
		if (to_print != 0)
		{
			ft_putstr(to_print);
			if (aux != 0)
				ft_putstr("-");
			print_hundreds(number, map, len - 1, aux);
		}
	}
	else if (len == 3)
		print_hundreds_aux(number, map, len, num);
}

void	print_hundreds_aux(char *number, t_map map, int len, unsigned int num)
{
	char	*to_find;

	print_hundreds(number, map, len, *number - '0');
	ft_putstr(" ");
	to_find = binary_search(100, map, 0, map.size);
	ft_putstr(to_find);
	if (num % 100 != 0)
		ft_putstr(" and ");
	print_hundreds(++number, map, len - 1, num % 100);
}
