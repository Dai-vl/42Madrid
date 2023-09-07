/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:36:59 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/29 12:37:00 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define TAM 4096

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

int	read_file(int fd)
{
	int		i;
	char	buffer[TAM];
	int		j;

	j = 0;
	i = read(fd, buffer, TAM);
	while (i != 0 &&i != -1)
	{
		buffer[i + 1] = '\0';
		write (1, buffer, i);
		i = read(fd, buffer, TAM);
	}

	close(fd);
	if (i == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	else if (argc != 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	fd = open_file(argv[1]);
	if (fd == -1 || read_file(fd) == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (0);
	}
	return (0);
}
