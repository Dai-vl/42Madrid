/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:35:47 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/10/01 16:25:50 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned long long int n, char *base)
{
	if (n >= 16)
	{
		ft_putnbr_base((n / 16), base);
		ft_putnbr_base((n % 16), base);
	}
	else
		ft_putchar_fd(base[n], 1);
}

static void	ft_putaddress(void *p)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base((unsigned long long int)p, "0123456789abcdef");
}

static void	apply_op(const char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_putaddress(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd(c, 1);
}

static void	read_format(char const *format, va_list args)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		else
		{
			apply_op(format[i + 1], args);
			i++;
		}
		i++;
	}
}

int	ft_printf(char const *format, ...)
{
	va_list	args;

	va_start(args, format);
	read_format(format, args);
	va_end(args);
	return (0);
}
// compile -o a.out ft_printf.c -L Libft -lft