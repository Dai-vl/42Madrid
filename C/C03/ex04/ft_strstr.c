/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:10:50 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/16 21:10:51 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*ret;
	char	*aux;
	char	*aux2;

	ret = 0;
	if (*to_find == '\0')
		return (str);
	while (*str != '\0' && ret == 0)
	{
		if (*str == *to_find)
		{
			ret = str;
			aux = str;
			aux2 = to_find;
		}
		while (*aux == *aux2 && *aux2 != '\0')
		{
			++aux;
			++aux2;
			if (*aux != *aux2 && *aux2 != '\0')
				ret = 0;
		}
		++str;
	}
	return (ret);
}
