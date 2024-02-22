int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	n = 0;
	while (str[i] == ' ')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		n = (n * 10) + (str[i] - '0');
		++i;
	}
	return (n * sign);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	int num;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		printf("%d\n", num);
	}
	return 0;
}