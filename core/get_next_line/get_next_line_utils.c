/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:52:31 by tbaker            #+#    #+#             */
/*   Updated: 2023/10/07 14:04:35 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char const *src, unsigned int n)
{
	char			*scopy;
	unsigned int	i;

	i = 0;
	scopy = malloc((n + 1) * sizeof(*scopy));
	if (!scopy)
		return (NULL);
	while (src[i] && i < n)
	{
		scopy[i] = src[i];
		i++;
	}
	while (i < n) //or <=
	{
		scopy[i] = '\0';//[i++]
		i++;
	}
	return (scopy);
}

int	ft_find_nl(char *buffer)
{
	int		i;

	i = 0;
	if (!buffer)
		return (0);
	if (buffer[0] == '\n')
	   return (1);	
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i++);
		i++;
	}
	return (0);
}

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc((len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (join - len);
}
