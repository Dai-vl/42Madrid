/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:35:47 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/10/02 12:35:57 by amato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long int n, char *base)
{
	if (n >= 16)
	{
		return (ft_putnbr_base((n / 16), base) + ft_putnbr_base((n % 16),
				base));
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		return (1);
	}
}

int	ft_putaddress(void *p)
{
	if (p == NULL)
		return (ft_putstr_fd("(nil)", 1), 5); //CAMBIAR
	ft_putstr_fd("0x", 1);
	return (2 + ft_putnbr_base((unsigned long long int)p, "0123456789abcdef"));
}

int	ft_strop(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	return (ft_putstr_fd(str, 1), ft_strlen(str));
}

int	bonus_putnbr(int num, int spf, int plf)
{
	if (plf == 1 && num > 0)
		ft_putchar_fd('+', 1);
	else if (spf == 1 && num > 0)
		ft_putchar_fd(' ', 1);
	return (ft_putnbr_fd(num, 1) + ((plf == 1 && num > 0) || (spf == 1
				&& num > 0)));
}

int	bonus_puthex(int hsf, unsigned int num)
{
	if (hsf == 1)
		ft_putstr_fd("0x", 1);
	return (ft_putnbr_base(num, "0123456789abcdef") + hsf);
}

int	apply_op(const char c, va_list args, int flags[])
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (c == 's')
		return (ft_strop(args));
	else if (c == 'p')
		return (ft_putaddress(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (bonus_putnbr(va_arg(args, int), flags[sp], flags[pl]));
	else if (c == 'u')
		return (bonus_puthex(flags[hs], va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar_fd('%', 1), 1);
	return (0);
}

int	ft_printf(char const *fr, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		flags[3];

	(len = 0, i = 0, va_start(args, fr));
	while (fr[i])
	{
		if (fr[i] != '%')
			(ft_putchar_fd(fr[i], 1), len++);
		else
		{
			while (fr[i + 1] == ' ' || fr[i + 1] == '+' || fr[i + 1] == '#')
			{
				if (fr[i + 1] == ' ')
					(flags[sp] = 1, ++i);
				if (fr[i + 1] == '+')
					(flags[pl] = 1, ++i);
				if (fr[i + 1] == '#')
					(flags[hs] = 1, ++i);
			}
			(len += apply_op(fr[i + 1], args, flags), ++i);
		}
		i++;
	}
	return (va_end(args), len);
}
#include <stdio.h>

int	main(void)
{
	unsigned int	x;

	x = 1;
	printf("%+++ d\n", x);
	ft_printf("%+++ d\n", x);
	return (0);
}
// gcc -o a.out ft_printf.c -L libft -lft