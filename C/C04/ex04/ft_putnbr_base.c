/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:32:32 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/20 19:32:33 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	correct_base(char *base, int *tam_base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] && base[i] != '-' && base[i] != '+')
		++i;
	if (i == 1 || i == 0 || base[i] == '-' || base[i] == '+')
		return (0);
	*tam_base = i;
	i = 0;
	while (i < *tam_base)
	{
		j = i + 1;
		while (j < *tam_base)
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void	rec_to_base(int nbr, char *base, int tam_base)
{
	char	num;

	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		num = base[2 % tam_base];
		rec_to_base(147483648, base, tam_base);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		rec_to_base(-nbr, base, tam_base);
	}
	else if (nbr < tam_base)
	{
		num = base[nbr % tam_base];
		write(1, &num, 1);
	}
	else
	{
		num = base[(nbr % tam_base)];
		rec_to_base((nbr / tam_base), base, tam_base);
		write(1, &num, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	tam_base;

	if (!correct_base(base, &tam_base))
		return ;
	rec_to_base(nbr, base, tam_base);
}

/*int main()
{
	ft_putnbr_base(-32424, "01");
	return 0;
}*/