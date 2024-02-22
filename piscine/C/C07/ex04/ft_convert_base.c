/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:26:14 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/23 21:26:17 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		space(char str);
void	dec_to_base(int nbr, char **base_str, int tam_base);
int		calculate_memory(int nbr, int tam_base);

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
	while (space(*str))
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pos = -pos;
		++str;
	}
	return (to_dec(str, base, tam_base) * pos);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		convert;
	int		tam_base[2];
	char	*base_str[2];
	int		tam_final;

	if (!correct_base(base_from, &tam_base[0])
		|| !correct_base(base_to, &tam_base[1]))
		return (0);
	convert = ft_atoi_base(nbr, base_from);
	tam_final = calculate_memory(convert, tam_base[1]);
	base_str[0] = base_to;
	base_str[1] = malloc(tam_final * sizeof(char));
	dec_to_base(convert, base_str, tam_base[1]);
	return (base_str[1]);
}

#include <stdio.h>
int main()
{
	char *aux = ft_convert_base("10004", "0123456789", "0123456");
	printf("%s\n", aux);
	return (0);
}