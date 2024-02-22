/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:09:05 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/20 20:09:06 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	space(char str)
{
	return (str == ' ' || str == '\f' || str == '\r' || str == '\t'
		|| str == '\v' );
}

int	correct_base(char *base, int *tam_base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] && base[i] != '-' && base[i] != '+' && !space(base[i]))
		++i;
	if (i == 1 || i == 0 || base[i] == '-' || base[i] == '+' || space(base[i]))
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

int	get_index(char *c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == *c)
			return (i);
		++i;
	}
	return (-1);
}

int	to_dec(char *str, char *base, int tam_base)
{
	int	exp;
	int	num;
	int	exp2;
	int	aux;

	num = 0;
	exp = 0;
	while (str[exp])
		++exp;
	while (exp > 0)
	{
		aux = get_index(str, base);
		if (aux == -1)
			return (0);
		exp2 = exp;
		while (exp2 > 1)
		{
			aux *= tam_base;
			--exp2;
		}
		num += aux;
		++str;
		--exp;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	tam_base;
	int	pos;

	pos = 1;
	if (!correct_base(base, &tam_base))
		return (0);
	if (*str == '-')
	{
		pos = -pos;
		++str;
	}
	if (*str == '+')
		++str;
	return (to_dec(str, base, tam_base) * pos);
}

/*int main()
{
	int aux = ft_atoi_base("-2147483648", "0123456789");
	printf("%d", aux);
	return 0;
}*/