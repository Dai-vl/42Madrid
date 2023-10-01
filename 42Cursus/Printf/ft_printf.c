/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:35:47 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/10/01 17:38:07 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long int n, char *base)
{
	if (n >= 16)
	{
		ft_putnbr_base((n / 16), base);
		ft_putnbr_base((n % 16), base);
	}
	else
		ft_putchar_fd(base[n], 1);
}

void	ft_putaddress(void *p)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base((unsigned long long int)p, "0123456789abcdef");
}

void	apply_op(const char c, va_list args)
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

void	read_format(char const *format, va_list args)
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
/*#include <stdio.h>
int main()
{
	printf("%d: \n", ft_printf("Test 1:%c\n", '0') == printf("Test 1:%c\n", '0'));
	printf("%d: \n", ft_printf("Test 2: %c \n", '0') == printf("Test 2: %c \n", '0'));
	printf("%d: \n", ft_printf("Test 3: %c\n", '0' - 256) == printf("Test 3: %c\n", '0' - 256));
	printf("%d: \n", ft_printf("Test 4:%c \n", '0' + 256) == printf("Test 4:%c \n", '0' + 256));
	printf("%d: \n", ft_printf("Test 5: %c %c %c \n", '0', 0, '1') == printf("Test 5: %c %c %c \n", '0', 0, '1'));
	printf("%d: \n", ft_printf("Test 6: %c %c %c \n", ' ', ' ', ' ') == printf("Test 6: %c %c %c \n", ' ', ' ', ' '));
	printf("%d: \n", ft_printf("Test 7: %c %c %c \n", '1', '2', '3') == printf("Test 7: %c %c %c \n", '1', '2', '3'));
	printf("%d: \n", ft_printf("Test 8: %c %c %c \n", '2', '1', 0) == printf("Test 8: %c %c %c \n", '2', '1', 0));
	printf("%d: \n", ft_printf("Test 9: %c %c %c \n", 0, '1', '2') == printf("Test 9: %c %c %c \n", 0, '1', '2'));

	return 0;	
}*/
// compile -o a.out ft_printf.c -L Libft -lft