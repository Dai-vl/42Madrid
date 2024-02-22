#include <unistd.h>

int main(int argc, char **argv)
{
	int rep[128];
	int	i;
	int	index;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	i = 0;
	while (i < 128)
		rep[i++] = 0;
	i = 0;
	while (argv[1][i])
	{
		index = argv[1][i];
		if (!rep[index])
		{
			write(1, &argv[1][i], 1);
			rep[index] = 1;
		}
		++i;
	}
	i = 0;
	while (argv[2][i])
	{
		index = argv[2][i];
		if (!rep[index])
		{
			write(1, &argv[2][i], 1);
			rep[index] = 1;
		}
		++i;
	}
	write(1, "\n", 1);
	return 0;
}