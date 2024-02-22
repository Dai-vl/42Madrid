/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:35:47 by dvidal-l          #+#    #+#             */
/*   Updated: 2024/01/30 11:55:08 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long int n, char *base)
{
	int	s1;
	int	s2;

	if (n >= 16)
	{
		s1 = ft_putnbr_base((n / 16), base);
		if (s1 == -1)
			return (-1);
		s2 = ft_putnbr_base((n % 16), base);
		if (s2 == -1)
			return (-1);
		return (s1 + s2);
	}
	else
	{
		if (ft_putchar_fd(base[n], 1) == -1)
			return (-1);
		return (1);
	}
}

int	ft_putaddress(void *p)
{
	int	ret1;
	int	ret2;

	if (p == NULL)
		return (ft_putstr_fd("0x0", 1));
	ret1 = ft_putstr_fd("0x", 1);
	if (ret1 == -1)
		return (-1);
	ret2 = ft_putnbr_base((unsigned long long int)p, "0123456789abcdef");
	if (ret2 == -1)
		return (-1);
	return (ret1 + ret2);
}

int	ft_strop(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	return (ft_putstr_fd(str, 1));
}

int	apply_op(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_strop(args));
	else if (c == 'p')
		return (ft_putaddress(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		aux;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			if (ft_putchar_fd(format[i], 1) == -1)
				return (-1);
			len++;
			++i;
			continue ;
		}
		aux = apply_op(format[i + 1], args);
		if (aux == -1)
			return (-1);
		len += aux;
		i += 2;
	}
	return (va_end(args), len);
}
