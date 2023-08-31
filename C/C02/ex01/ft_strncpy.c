/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:53:19 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/13 16:53:21 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*p1;
	char			*p2;

	i = 0;
	p1 = src;
	p2 = dest;
	while (*p1 != '\0' && i < n)
	{
		*p2 = *p1;
		++p2;
		++p1;
		++i;
	}
	while (i < n)
	{
		*p2 = '\0';
		++p2;
		++i;
	}
	return (dest);
}
