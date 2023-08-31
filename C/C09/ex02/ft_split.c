/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:06:59 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/24 19:07:00 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char *sep, char *str, int i)
{
	int	j;
	int	ret;

	ret = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (sep[j] && sep[j] != str[i])
			++j;
		if (sep[j] == str[i])
			++ret;
		if (sep[j] == '\0' && !ret)
			return (0);
		else if (sep[j] == '\0')
			return (ret);
		++i;
	}
	if (!str[i] && !ret)
		return (0);
	return (ret);
}

int	str_len(char *str, char *sep, int i)
{
	int	size;
	int	j;

	size = 0;
	while (str[i])
	{
		j = 0;
		while (sep[j] && sep[j] != str[i])
			++j;
		if (sep[j] == str[i])
			break ;
		++size;
		++i;
	}
	return (size);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	while (src[i])
		++i;
	ret = malloc(i * sizeof(char) + 1);
	if (ret == 0)
		return (0);
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

void	copy_words(char *str, char *charset, char **ret, int i)
{
	int		aux;
	int		j;
	char	*word;

	j = 0;
	while (str[i])
	{
		if (is_separator(charset, str, i) == 0)
		{
			aux = str_len(str, charset, i);
			word = malloc((str_len(str, charset, i) + 1) * sizeof(char));
			if (word == 0)
				return ;
			while (str[i] && is_separator(charset, str, i) == 0)
				*word++ = str[i++];
			*word = '\0';
			word -= aux;
		}
		aux = is_separator(charset, str, i);
		if (aux != 0 || str[i] == '\0')
		{
			ret[j++] = ft_strdup(word);
			i += aux;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		count_words;
	int		i;
	int		aux;

	i = 0;
	i += is_separator(charset, str, 0);
	count_words = 0;
	while (str[i])
	{
		i += str_len(str, charset, i);
		aux = is_separator(charset, str, i);
		if (aux != 0 || str[i] == '\0')
		{
			++count_words;
			i += aux;
		}
	}
	ret = malloc((count_words + 1) * sizeof(char *));
	if (ret == 0)
		return (ret);
	i = is_separator(charset, str, 0);
	copy_words(str, charset, ret, i);
	ret[count_words] = 0;
	return (ret);
}

/*#include <stdio.h>
int main()
{
	char **hola = ft_split("- --hola-que-tal-lavida-", "-");

	while (*hola != 0)
	{
		printf("%s\n", *hola);
		++hola;
	}
	return 0;
}*/