/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:22:40 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/19 16:57:52 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_copyword(char const *s, int i, char c)
{
	char	*scopy;
	int		len;
	int		i_pos;
	int		j;

	j = 0;
	len = 0;
	i_pos = i;
	while (s[i_pos] != '\0' && s[i_pos] != c)
	{
		len++;
		i_pos++;
	}
	scopy = (char *)malloc(sizeof(char) * (len + 1));
	if (scopy == NULL)
		return (NULL);
	i_pos = i;
	while (j < len)
	{
		scopy[j] = s[i_pos];
		i_pos++;
		j++;
	}
	scopy[j] = '\0';
	return (scopy);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		jlen;
	int		j;
	int		i;

	i = 0;
	j = 0;
	jlen = ft_wcount(s, c);
	array = (char **)malloc(sizeof(char *) * (jlen + 1));
	if (array == NULL)
		return (NULL);
	while (s[i] != '\0' && j < jlen)
	{
		if (s[i] != c && s[i] != '\0')
		{
			array[j] = ft_copyword(s, i, c);
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		if (s[i] != '\0' && s[i] == c && j < jlen)
			i++;
	}
	array[j] = NULL;
	return (array);
}
