/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:53:41 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/17 11:53:42 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_size;
	unsigned int	dest_size;

	j = 0;
	src_size = ft_strlen(src);
	while (dest[j] != '\0')
	{
		++j;
	}
	if (size == 0 || size <= j)
		return (src_size + size);
	dest_size = j;
	i = 0;
	while (src[i] != '\0' && i < size - dest_size - 1)
	{
		dest[j] = src[i];
		++j;
		++i;
	}
	dest[j] = '\0';
	return (src_size + dest_size);
}
