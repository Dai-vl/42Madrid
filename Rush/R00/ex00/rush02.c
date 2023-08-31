/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoribio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:31:28 by ctoribio          #+#    #+#             */
/*   Updated: 2023/08/13 16:48:02 by ctoribio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	f_aux(int width, char first_char, char mid_char)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i == 0 || i == width - 1)
			ft_putchar(first_char);
		else
			ft_putchar(mid_char);
		++i;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0)
			f_aux(x, 'A', 'B');
		else if (i == y - 1)
			f_aux(x, 'C', 'B');
		else
			f_aux(x, 'B', ' ');
		++i;
	}
}
