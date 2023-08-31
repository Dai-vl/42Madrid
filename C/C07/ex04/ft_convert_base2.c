/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:26:29 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/23 21:26:31 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	space(char str)
{
	return (str == ' ' || str == '\f' || str == '\r' || str == '\t'
		|| str == '\v' );
}

int	calculate_memory(int nbr, int tam_base)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= tam_base;
		++i;
	}
	return (i + 1);
}

void	str_rev(char *str)
{
	int		size;
	int		i;
	int		j;
	char	aux;

	i = 0;
	size = 0;
	while (str[i] != '\0')
		++i;
	size = i;
	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		++i;
		--j;
	}
}

void	loop_to_base(int nbr, int tam_base, char **base_str, int *i)
{
	while (nbr >= tam_base)
	{
		base_str[1][*i] = base_str[0][(nbr % tam_base)];
		nbr = nbr / tam_base;
		++(*i);
	}
	if (nbr < tam_base)
	{
		base_str[1][*i] = base_str[0][nbr % tam_base];
	}
}

void	dec_to_base(int nbr, char **base_str, int tam_base)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		loop_to_base(147483648, tam_base, base_str, &i);
		++i;
		loop_to_base(2, tam_base, base_str, &i);
		++i;
		base_str[1][i] = '-';
	}
	else if (nbr < 0)
	{
		loop_to_base(-nbr, tam_base, base_str, &i);
		++i;
		base_str[1][i] = '-';
	}
	else
		loop_to_base(nbr, tam_base, base_str, &i);
	base_str[1][i + 1] = '\0';
	str_rev(base_str[1]);
}
