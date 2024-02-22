/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:25:20 by dvidal-l          #+#    #+#             */
/*   Updated: 2024/01/31 13:25:22 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	if (rd == -1)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = '\0';
	}
	prep_buffer(buffer);
	if (!line)
		return (NULL);
	return (line);
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
	if (ret)
		free(ret);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffers[MAX_FD][BUFFER_SIZE + 1];
	char		*ret;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ret = ft_strdup(buffers[fd]);
	if (!ret)
		return (NULL);
	if (ft_strchr(buffers[fd], '\n'))
		return (return_line(ret, buffers[fd], 0));
	rd = read(fd, buffers[fd], BUFFER_SIZE);
	if (rd == -1 || (!rd && !ft_strlen(ret)))
		return (read_error(rd, buffers[fd], ret));
	while (rd > 0)
	{
		buffers[fd][rd] = '\0';
		ret = ft_strjoin(ret, buffers[fd]);
		if (!ret)
			return (read_error(rd, buffers[fd], ret));
		if (ft_strchr(buffers[fd], '\n'))
			break ;
		rd = read(fd, buffers[fd], BUFFER_SIZE);
	}
	return (return_line(ret, buffers[fd], rd));
}
