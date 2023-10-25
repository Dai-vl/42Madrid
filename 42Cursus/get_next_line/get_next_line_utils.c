/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:39:05 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/10/25 18:21:40 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret || !s)
		return (0);
	i = 0;
	while (s[start] && i < len)
	{
		ret[i] = s[start];
		++i;
		++start;
	}
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	num;

	num = 0;
	while (s[num])
		++num;
	return (num);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	i = 0;
	while (s1[i])
		++i;
	ret = malloc((i + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	i = 0;
	while (*s1)
	{
		ret[i] = *s1;
		++i;
		++s1;
	}
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_size;
	size_t	dest_size;

	j = 0;
	src_size = ft_strlen(src);
	while (dst[j] != '\0')
		++j;
	if (dstsize == 0 || dstsize <= j)
		return (src_size + dstsize);
	dest_size = j;
	i = 0;
	while (src[i] != '\0' && i < dstsize - dest_size - 1)
	{
		dst[j] = src[i];
		++j;
		++i;
	}
	dst[j] = '\0';
	return (src_size + dest_size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	while (dstsize != 0 && src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		++i;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}
