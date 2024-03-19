/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:23:22 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/19 16:49:41 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_overlap(void *dest, const void *src, size_t n)
{
	char		*destcopy;
	const char	*srccopy;

	destcopy = (char *)dest;
	srccopy = (const char *)src;
	while (n > 0)
	{
		n--;
		destcopy[n] = srccopy[n];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest2 = (char *)dest;
	src2 = (const char *)src;
	i = 0;
	if (src2 < dest2)
	{
		return (ft_overlap(dest, src, n));
	}
	else
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest);
}
