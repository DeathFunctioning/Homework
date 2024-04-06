/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:14:52 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/19 16:46:50 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*str1;
	size_t				i;

	str1 = (const unsigned char *) str;
	i = 0;
	while (i < n)
	{
		if (str1[i] == (unsigned char)c)
			return ((void *)&str1[i]);
		i++;
	}
	return (NULL);
}
