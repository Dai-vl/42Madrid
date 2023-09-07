/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:52:31 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/09 19:52:34 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_vars(char *fst, char snd[], char trd[])
{
	*fst = '0';
	snd[0] = '1';
	trd[0] = '3';
	snd[1] = '1';
	trd[1] = '2';
	trd[2] = '2';
}

void	write_vars(char fst, char snd[], char trd[])
{
	write(1, ", ", 2);
	write(1, &fst, 1);
	write(1, &snd[0], 1);
	write(1, &trd[0], 1);
	++trd[0];
}

void	update1(char snd[], char trd[])
{
	++trd[1];
	trd[0] = trd[1];
	++snd[0];
}

void	update2(char *fst, char snd[], char trd[])
{
	*fst += 1;
	++snd[1];
	snd[0] = snd[1];
	++trd[2];
	trd[0] = trd[2];
	trd[1] = trd[2];
}

void	ft_print_comb(void)
{
	char		fst;
	char		snd[2];
	char		trd[3];

	write(1, "012", 3);
	init_vars(&fst, snd, trd);
	while (fst <= '7')
	{
		while (snd[0] <= '8')
		{
			while (trd[0] <= '9')
			{	
				write_vars(fst, snd, trd);
			}
			update1(snd, trd);
		}
		update2(&fst, snd, trd);
	}
}
