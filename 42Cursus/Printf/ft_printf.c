/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amato <amato@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:35:47 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/10/02 12:03:28 by amato            ###   ########.fr       */
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
		return (ft_putstr_fd("(nil)", 1), 5);
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

int	apply_op(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
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
		return (ft_putchar_fd('%', 1), 1);
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			(ft_putchar_fd(format[i], 1), len++);
		else
		{
			len += apply_op(format[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
