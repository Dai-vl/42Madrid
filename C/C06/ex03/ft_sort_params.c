/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:38:33 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/22 13:38:35 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		++s1;
		++s2;
	}
	if (*s1 != '\0')
		return (1);
	else if (*s2 != '\0')
		return (-1);
	return (0);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	sort(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) == 1)
				ft_swap(&argv[j], &argv[j + 1]);
			++j;
		}
		++i;
	}
}

int	main(int argc, char *argv[])
{
	int	arg;

	if (argc == 1)
		return (0);
	sort(argc, argv);
	arg = 1;
	while (arg < argc)
	{
		while (*argv[arg])
		{
			write(1, argv[arg], 1);
			++argv[arg];
		}
		write(1, "\n", 1);
		++arg;
	}
}
