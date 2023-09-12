#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		write(1, "\n", 1);
		return 0;
	}
	ft_putstr(argv[argc - 1]);
	return 0;
}