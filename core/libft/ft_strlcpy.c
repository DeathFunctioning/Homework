/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:13:08 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:14:14 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < (destsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

/*int	main(void)
{
	char *src = "hello world";
	char *src2 = "hello world";
	char *dest = "hello world";
	char *dest2 = "goodbye old friend";
	size_t destsize = 11;

	printf("%s\n", dest);
	printf("%s\n", dest2);
	printf("%s\n", src);
	printf("%s\n", src2);
	printf("%lu\n", ft_strlcpy(dest, src, destsize)); 
//	ft_strlcpy(dest, src, destsize); 
	printf("%lu\n", strlcpy(dest2, src2, destsize)); 
	printf("%s\n", dest);
	printf("%s\n", dest2);
	printf("%s\n", src);
	printf("%s\n", src2);
	return (0);
}*/
