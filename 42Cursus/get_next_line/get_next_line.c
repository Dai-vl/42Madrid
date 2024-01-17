/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dai <dai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:39:07 by dvidal-l          #+#    #+#             */
/*   Updated: 2024/01/17 21:14:47 by dai              ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		++i;
	}
	if ((char) c == s[i])
		return ((char *) s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		sl;
	int		i;
	char	*ret;

	sl = ft_strlen(s1);
	len = sl + ft_strlen(s2);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	sl = 0;
	while (s1[i])
		ret[sl++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[sl++] = s2[i++];
	ret[sl] = '\0';
	return (ret);
}
//--------------------------------------------------------------------------------------------

void	prep_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		++i;
	if (buffer[i] == '\n')
	{
		++i;
		while (buffer[i])
		{
			buffer[j++] = buffer[i];
			buffer[i++] = '\0';
		}
		buffer[j] = '\0';
	}
}

char	*return_line(char *buffer)
{
	int		i;
	char	*ret;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		++i;
	ret = ft_substr(buffer, 0, i + 1);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ret = ft_strdup(buffer);
	if (ft_strchr(buffer, '\n'))
	{
		prep_buffer(buffer);
		return (return_line(ret));
	}
	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd == -1 || (rd == 0 && !ret))
		return (0);
	while (rd > 0)
	{
		buffer[rd] = '\0';
		ret = ft_strjoin(ret, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		rd = read(fd, buffer, BUFFER_SIZE);
	}
	prep_buffer(buffer);
	return (return_line(ret));
}

#include <stdio.h>

int	main(void)
{
	int fd = open("hola.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	return (0);
}