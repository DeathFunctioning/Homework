/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:52:31 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/17 16:42:29 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_nl(char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	temp = buffer;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * len + 1);
	if (!join)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (join - len);
}
