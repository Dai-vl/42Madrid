/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:27:25 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/13 19:27:27 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*p1;
	char			*p2;
	unsigned int	size_src;

	size_src = 0;
	p1 = src;
	p2 = dest;
	if (size > 0)
	{
		while (*p1 != '\0' && size_src < size -1)
		{
			*p2 = *p1;
			++p2;
			++p1;
			++size_src;
		}
	}
	*p2 = '\0';
	while (*p1 != '\0')
	{
		++size_src;
		++p1;
	}
	return (size_src);
}
