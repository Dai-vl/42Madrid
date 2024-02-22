/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:48:59 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/14 12:49:00 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

#define MAX_SIZE 16
#define LINE_HEX 40

const static char	g_hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'a', 'b', 'c', 'd', 'e', 'f'};

void	print_address(intptr_t addr)
{
	char	char_address[MAX_SIZE];
	int		i;

	i = MAX_SIZE -1;
	while (i >= 0 && addr >= 16)
	{
		char_address[i] = g_hex[addr % 16];
		addr = addr / 16;
		--i;
	}
	char_address[i] = g_hex[addr];
	--i;
	while (i >= 0)
	{
		char_address[i] = '0';
		--i;
	}
	++i;
	while (i < MAX_SIZE)
	{
		write(1, &char_address[i], 1);
		i++;
	}
	write(1, ":", 1);
}

void	to_hex(char src)
{
	char	aux;

	aux = g_hex[(unsigned char)src / 16];
	write(1, &aux, 1);
	aux = g_hex[(unsigned char)src % 16];
	write(1, &aux, 1);
}

void	second_column(char *line, int i, int size)
{
	int	j;
	int	spaces;

	j = 0;
	spaces = 0;
	while (j < MAX_SIZE && i < size)
	{
		if (j % 2 == 0)
		{
			write(1, " ", 1);
			++spaces;
		}
		to_hex(*line);
		spaces += 2;
		++line;
		++i;
		++j;
	}
	write(1, " ", 1);
	while (spaces < LINE_HEX)
	{
		write(1, " ", 1);
		++spaces;
	}
}

int	third_column(char *line, int i, int size)
{
	int	j;
	int	i_aux;

	i_aux = i;
	j = 0;
	while (j < MAX_SIZE && i_aux < size)
	{
		if (*line < 32 || *line > 126)
			write(1, ".", 1);
		else
			write(1, line, 1);
		++line;
		++i_aux;
		++j;
	}
	return (j);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;
	char			*content;
	intptr_t		p_addres;

	content = (char *)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		p_addres = (intptr_t) addr;
		print_address(p_addres);
		second_column(content, i, size);
		j = third_column(content, i, size);
		content += j;
		i += j;
		addr += j;
		write(1, "\n", 1);
	}
	return (addr);
}
