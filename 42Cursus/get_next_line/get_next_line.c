/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:39:07 by dvidal-l          #+#    #+#             */
/*   Updated: 2024/01/30 13:23:11 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	prep_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n' )
		++i;
	if (buffer[i] == '\n')
		++i;
	while (i < BUFFER_SIZE)
	{
		buffer[j++] = buffer[i];
		buffer[i++] = '\0';
	}
	buffer[j] = '\0';
}

char	*return_line(char *line, char *buffer, int rd)
{
	int		i;
	char	*aux;
	char	*ret;

	if (rd == -1)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = '\0';
	}
	prep_buffer(buffer);
	i = 0;
	while (line[i] && line[i] != '\n')
		++i;
	aux = ft_substr(line, 0, i + 1);
	ret = ft_strdup(aux);
	free(line);
	free(aux);
	return (ret);
}

char	*read_error(int rd, char *buffer, char *ret)
{
	int	i;

	if (rd == -1)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = '\0';
	}
	free(ret);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ret = ft_strdup(buffer);
	if (!ret)
		return (0);
	if (ft_strchr(buffer, '\n'))
		return (return_line(ret, buffer, 0));
	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd == -1 || (!rd && !ft_strlen(ret)))
		return (read_error(rd, buffer, ret));
	while (rd > 0)
	{
		buffer[rd] = '\0';
		ret = ft_strjoin(ret, buffer);
		if (!ret)
			return (0);
		if (ft_strchr(buffer, '\n'))
			break ;
		rd = read(fd, buffer, BUFFER_SIZE);
	}
	return (return_line(ret, buffer, rd));
}

/*
#include <stdio.h>

int	main(void)
{
	int fd = open("hola.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}*/