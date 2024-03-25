/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:43:49 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/19 16:52:53 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	str2len;

	i = 0;
	str2len = ft_strlen(str2);
	if (str2 == NULL)
		return ((char *)str1);
	if (str2len == 0)
		return ((char *)str1);
	while (str1[i] != '\0' && i <= n)
	{
		j = 0;
		while (str1[i + j] == str2[j] && i + j < n)
		{
			if (str2[j + 1] == '\0')
				return ((char *)&str1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
