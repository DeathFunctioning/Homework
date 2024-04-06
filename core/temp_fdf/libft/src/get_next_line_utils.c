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

//Same as strdup but up to n
char	*gnl_strndup(const char *src, int n)
{
	char			*scopy;
	int				len;

	len = gnl_strlen(src);
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

char	*gnl_strchr(const char *src, int c)
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

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

//allows s1 as NULL and gets the iterators i and j as args
char	*gnl_strjoin(const char *s1, const char *s2, int i, int j)
{
	char	*join;
	int		len_s1;
	int		len_s2;

	if (!s1)
		len_s1 = 0;
	else
		len_s1 = gnl_strlen(s1);
	len_s2 = gnl_strlen(s2);
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
