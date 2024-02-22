/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoribio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:31:28 by ctoribio          #+#    #+#             */
/*   Updated: 2023/08/13 16:47:53 by ctoribio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	f_aux(int width, char first_char, char mid_char, char last_char)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i == 0)
			ft_putchar(first_char);
		else if (i == width - 1)
			ft_putchar(last_char);
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
			f_aux(x, '/', '*', '\\');
		else if (i == y - 1)
			f_aux(x, '\\', '*', '/');
		else
			f_aux(x, '*', ' ', '*');
		++i;
	}
}
