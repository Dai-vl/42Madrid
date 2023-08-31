/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 02:10:42 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/31 02:10:43 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "things.h"

const char	g_ops[5] = {'+', '-', '/', '%', '*'};

void	calculate(int v1, int v2, char op)
{
	int		(*f[5])(int, int);
	int		ret;
	int		i;

	f[0] = &ft_add;
	f[1] = &ft_sub;
	f[2] = &ft_div;
	f[3] = &ft_mod;
	f[4] = &ft_mul;
	i = 0;
	while (i < 5)
	{
		if (op == g_ops[i])
			ret = f[i](v1, v2);
		++i;
	}
	ft_putnbr(ret);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		v[2];
	char	op;

	if (argc != 4)
		return (0);
	v[0] = ft_atoi(argv[1]);
	v[1] = ft_atoi(argv[3]);
	op = *argv[2];
	if (op != '+' && op != '-' && op != '/' && op != '*' && op != '%')
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (op == '/' && v[1] == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (op == '%' && v[1] == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	calculate(v[0], v[1], op);
	return (0);
}
