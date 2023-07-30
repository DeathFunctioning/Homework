/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:23:22 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/30 20:21:07 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	dest2 = (char *)dest;
	src2 = (const char *)src;
	i = 0;
	if (src2 < dest2)
	{
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	else
	{
		while (i > n)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest);
}
/*
int main(void)
{
//	char src[5] = { 's', 'a', '\0', 'c', 'h'};
	char src[5] = "kkkkk";
	char dest[7] = "hello!!";
//	char dest1[6] = { 'k', '\0', 'k', 'k', 'k', 'k'};
	char dest1[7] = "hello!!";
	int	i = 0;
	ft_memmove(dest, src, 5);
	while (i < 7)
	{
		printf("%c\n", dest[i]);
		i++;
	}
	printf("----------------------");
	printf("\n");
	memmove(dest1, src, 5);
	i = 0;
	while (i < 7)
	{
		printf("%c\n", dest1[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
