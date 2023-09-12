#include <stdlib.h>

int		*fill(int start, int end)
{
	int *ret;

	ret = malloc ((end - start + 1) * sizeof(int));
	int i = start;
	int d = 0;
	while (i <= end)
	{
		ret[d] = i;
		++i;
		++d;
	}
	return (ret);
}

int     *ft_range(int start, int end)
{
	int	*ret;

	if (start > end)
		ret = fill(end, start);
	else
		ret = fill(start, end);
	return (ret);
}

#include <stdio.h>
int main()
{
	int *cosa = ft_range(0, 0);
	int i = 0;
	while (i < (1))
	{
		printf("%d ", cosa[i]);
		++i;
	}
	printf("\n");
	return 0;
}