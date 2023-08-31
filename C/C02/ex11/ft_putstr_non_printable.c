/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:00:44 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/13 20:00:45 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const static char	g_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'a', 'b', 'c', 'd', 'e', 'f'};

void	to_hex(char src)
{
	char	aux;

	write(1, "\\", 1);
	aux = g_hex[(unsigned char)src / 16];
	write(1, &aux, 1);
	aux = g_hex[(unsigned char)src % 16];
	write(1, &aux, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
		{
			to_hex(*str);
		}
		else
			write(1, str, 1);
		++str;
	}
}
