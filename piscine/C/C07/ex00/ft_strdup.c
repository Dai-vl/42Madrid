/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:09:02 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/23 19:09:03 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

/*#include <stdio.h>
int main()
{
	char *aux = ft_strdup("HOLA");
	printf("%s", aux);
	return (0);
}*/