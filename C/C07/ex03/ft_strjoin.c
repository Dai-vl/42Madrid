/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:42:58 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/23 20:42:59 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		num;

	num = 0;
	while (*str != '\0')
	{
		++num;
		++str;
	}
	return (num);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*ps;
	char	*pd;

	ps = src;
	pd = dest;
	while (*pd != '\0')
	{
		++pd;
	}
	while (*ps != '\0')
	{
		*pd = *ps;
		++pd;
		++ps;
	}
	*pd = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*p1;
	char	*p2;

	p1 = src;
	p2 = dest;
	while (*p1 != '\0')
	{
		*p2 = *p1;
		++p2;
		++p1;
	}
	*p2 = '\0';
	return (dest);
}

int	cal_size(char **strs, int size, char *sep)
{
	int	i;
	int	total_size;

	total_size = 0;
	i = 0;
	while (i < size)
	{
		total_size += ft_strlen(strs[i]);
		++i;
	}
	total_size += (ft_strlen(sep) * (size - 1)) + 1;
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		total_size;
	int		i;

	i = 1;
	if (size <= 0)
	{
		ret = malloc(sizeof(char));
		ret[0] = '\0';
		return (ret);
	}
	total_size = cal_size(strs, size, sep);
	ret = malloc(total_size * sizeof(char));
	ret = ft_strcpy(ret, strs[0]);
	while (i < size)
	{
		ret = ft_strcat(ret, sep);
		ret = ft_strcat(ret, strs[i]);
		++i;
	}
	return (ret);
}

/*#include <stdio.h>
int main()
{
	char *strs[] = {"a", "", "b"};
	char *aux = ft_strjoin(3, strs, "-");

	printf("%s\n", aux);
	return (0);
}*/