/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:41:42 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/31 14:41:43 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include <fcntl.h>

#define TAM 4096

void	ft_putstr(char *str, int fd)
{
	while (*str != '\0')
	{
		write(fd, str, 1);
		str++;
	}
}

void	ft_cat_in(void)
{
	char	buffer[TAM];
	int		aux;

	aux = read(STDIN_FILENO, buffer, TAM);
	while (aux != 0 && aux != -1)
	{
		buffer[aux] = '\0';
		write(1, buffer, aux);
		aux = read(STDIN_FILENO, buffer, TAM);
	}
}

void	print_error(char *prog, char *path, int error)
{
	ft_putstr(basename(prog), 2);
	ft_putstr(": ", 2);
	ft_putstr(basename(path), 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(error), 2);
	ft_putstr("\n", 2);
}

void	ft_cat(char *path, char *prog)
{
	int		fd;
	char	buffer[TAM];
	int		aux;

	if (*path == '-')
		ft_cat_in();
	else
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
			print_error(prog, path, errno);
		aux = read(fd, buffer, TAM);
		while (aux != 0 && aux != -1)
		{
			buffer[aux] = '\0';
			write(1, buffer, aux);
			aux = read(fd, buffer, TAM);
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1 || *argv[1] == '-')
		ft_cat_in();
	else
	{
		while (i < argc)
		{
			ft_cat(argv[i], argv[0]);
			++i;
		}
	}
	return (0);
}
