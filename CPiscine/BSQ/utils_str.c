/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:51:37 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/30 13:51:38 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	while (src[i])
		++i;
	ret = malloc((i + 1) * sizeof(char));
	i = 0;
	while (*src)
	{
		ret[i] = *src;
		++i;
		++src;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_realloc(char *arr, int *curr_size)
{
	char	*new;
	int		i;

	i = 0;
	*curr_size *= 2;
	new = malloc(*curr_size * sizeof(char));
	while (i < (*curr_size) / 2)
	{
		new[i] = arr[i];
		++i;
	}
	free(arr);
	return (new);
}

int	val_symbol(char c, t_data crs)
{
	return (c == crs.empty || c == crs.obs);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	store_chars(t_data *crs, char *line, int i)
{
	if (i > 3)
	{
		crs->full = line[--i];
		crs->obs = line[--i];
		crs->empty = line[--i];
		line[i] = '\0';
		if (i >= 10 || (i == 10 && ft_strcmp(&line[i], "2147483647") > 0))
		{
			crs->lines = FAIL;
			free(line);
			return ;
		}
		crs->lines = ft_atoi(line);
	}
	free(line);
}
