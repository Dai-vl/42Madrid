#include <unistd.h>

void	ft_putnbr(int n)
{
	char	aux;
	int		nd;

	if (n <= 9)
	{
		aux = n + '0';
		write(1, &aux, 1);
	}
	else
	{
		nd = n % 10;
		aux = nd + '0';
		ft_putnbr(n / 10);
		write(1, &aux, 1);
	}
}

int main()
{
	int		i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		++i;
	}
	return (0);
}