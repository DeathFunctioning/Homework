/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:23:22 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/12 18:27:20 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src1;
	char	*dest1;
	char	temp[n];
	size_t	i;

	i = 0;
	src1 = (char *)src;
	dest1 = (char *)dest;
	while (i < n)
	{
		temp[i] = src1[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest1[i] = temp[i];
		i++;
	}
	return (dest1);
}
/*
int main(void)
{
	char src[5] = { 's', 'a', '\0', 'c', 'h'};
	char dest[5];
	char dest1[5];
	int	i = 0;
	ft_memmove(dest, src, 5);
	while (i < 5)
	{
		printf("%c\n", dest[i]);
		i++;
	}
	printf("----------------------");
	printf("\n");
	memmove(dest1, src, 5);
	i = 0;
	while (i < 5)
	{
		printf("%c\n", dest1[i]);
		i++;
	}
	return (0);
}*/
