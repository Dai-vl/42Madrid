#include <unistd.h>
#include <stdio.h>

int is_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z' ) || (c >= 'a' && c <= 'z'));
}

int main(int argc, char **argv)
{
	char ap[128];
	int index;
	
	//argc = 2;
	//argv[1] = ".My Hyze 47y 7.";
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	while (i < 128)
		ap[i++] = 0;
	i = 0;
	while (argv[1][i])
	{
		if (is_alpha(argv[1][i]))
		{
			index = argv[1][i];
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				index += 32;
			ap[index] += 1;
		}
		++i;
	}
	i = 0;
	int flag = 0;
	while (argv[1][i])
	{
		index = argv[1][i];
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			index += 32;
		if (ap[index] != 0)
		{
			if (flag)
				printf(", ");
			printf("%d%c", ap[index], (char)index);
			ap[index] = 0;
			flag = 1;
		}
		++i;
	}
	printf("\n");
	return 0;
}