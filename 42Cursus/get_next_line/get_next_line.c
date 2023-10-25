/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:39:07 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/10/25 19:02:51 by dvidal-l         ###   ########.fr       */
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

//------------------------------------------------------------------------------------------------------------------------

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*or;

	if (!dst && !src)
		return (0);
	or = dst;
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *) src)[i];
		++i;
	}
	return (or);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*or;
	char	*sr;

	or = (char *)dst;
	sr = (char *)src;
	if (or < sr)
		ft_memcpy(or, sr, len);
	else if (or > sr)
	{
		i = len;
		while (i > 0)
		{
			--i;
			or[i] = sr[i];
		}
	}
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	ant[BUFFER_SIZE];
	char		buffer[BUFFER_SIZE];
	int			i;
	int			j;
	char		*ret;
	int			enc;

	if (fd == -1)
		return (NULL);
	i = 0;
	while (ant[i] && ant[i] != '\n')
		++i;
	ret = ft_substr(ant, 0, i);
	read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (i < BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
		++i;
	ft_strlcat(ret, buffer, ft_strlen(ret) + i + 1);
	while (buffer[i - 1] && buffer[i - 1] != '\n')
	{
		read(fd, buffer, BUFFER_SIZE);
		i = 0;
		while (i < BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
			++i;
		ft_strlcat(ret, buffer, ft_strlen(ret) + i + 1);
	}
	j = 0;
	while (ant[j] && ant[j] != '\n')
		++j;
	ft_memmove(&ant[0], &ant[j], ft_strlen(&ant[j]));
	j = 0;
	++i;
	while (i < BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
		ant[j++] = buffer[i++];
	return (ret);
}

#include <stdio.h>
int	main(void){

	int fd = open("hola.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));

	return (0);
}