#include <stdlib.h>

int		count_words(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n' && 
			(str[i + 1] == ' ' || str[i+1] == '\t' || str[i + 1] == '\0' || str[i+1] == '\n'))
			++count;
		++i;
	}
	return count;
}

int ft_strlen(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
		{
			++count;
		}
		else
			return (count);
		++i;
	}
	return count;
}

char    **ft_split(char *str)
{
	int count = count_words(str);
	char **ret;
	int i = 0;
	int j = 0;
	int index = 0;

	ret = malloc(count * sizeof(char*));
	ret[index] = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (index < count)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
		{
			ret[index][j] = str[i];
			++j;
		}
		else
		{
			j = 0;
			index++;
			ret[index] = malloc(ft_strlen(str) * sizeof(char));
		}
		++i;
	}
	ret[index] = 0;
	return (ret);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 0)
		return 0;
	char **cosas;
	cosas = ft_split(argv[1]);
	int i = 0;
	while (cosas[i] != 0)
	{
		printf("%s\n", cosas[i]);
		++i;
	}
}