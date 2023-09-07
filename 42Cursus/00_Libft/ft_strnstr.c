/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:14:03 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/09/07 14:16:51 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find, unsigned int blen)
{
	char			*ret;
	char			*aux;
	char			*aux2;
	unsigned int	i;

	i = 0;
	ret = 0;
	if (*to_find == '\0')
		return (str);
	while (*str != '\0' && ret == 0 && i < blen)
	{
		if (*str == *to_find)
		{
			ret = str;
			aux = str;
			aux2 = to_find;
		}
		while (*aux == *aux2 && *aux2 != '\0' && i < blen)
		{
			++aux;
			++aux2;
			if (*aux != *aux2 && *aux2 != '\0')
				ret = 0;
		}
		++str;
		++i;
	}
	return (ret);
}