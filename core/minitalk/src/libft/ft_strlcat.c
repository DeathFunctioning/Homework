/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:16:22 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/19 16:51:02 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	destlen = i;
	if (size == 0)
		return (destlen + srclen);
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (destlen < size)
		dest[i] = '\0';
	return (destlen + srclen);
}
