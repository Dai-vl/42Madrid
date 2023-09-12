char    *ft_strrev(char *str)
{
	int	j;
	int i;
	char	aux;

	j = 0;
	while (str[j])
		++j;
	--j;
	i = 0;
	while (i < j)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		++i;
		--j;
	}
	return (str);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return 0;
	}
	char *aux = ft_strrev(argv[1]);
	printf("%s\n", aux);
	return 0;
}