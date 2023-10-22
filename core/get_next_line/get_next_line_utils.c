/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:52:31 by tbaker            #+#    #+#             */
/*   Updated: 2023/10/07 17:56:38 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *src, int n)
{
	char			*scopy;
	int				len;

	len = ft_strlen(src);
	if (len > n)
		len = n;
	scopy = (char *)malloc((n + 1) * sizeof(char));
	if (!scopy)
		return (NULL);
	scopy[len] = '\0';
	while (len--)
		scopy[len] = src[len];
	return (scopy);
}

char	*ft_strchr(const char *src, int c)
{
	const char	*ptr;

	if (!src)
		return (NULL);
	ptr = src;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
			return ((char *)ptr);
		ptr++;
	}
	if ((char)c == '\0')
		return ((char *)ptr);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2, int i, int j)
{
	char	*join;
	int		len_s1;
	int		len_s2;

	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < len_s1)
	{
		join[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}
