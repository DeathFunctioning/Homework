/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:37:35 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/19 16:58:25 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_nbrlen(long n)
{
	long	count;
	int		nb;

	nb = n;
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		nb = -n;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*ft_minint(void)
{
	char	*value;

	value = (char *)malloc(sizeof(char) * 12);
	if (value == NULL)
		return (NULL);
	ft_strlcpy(value, "-2147483648", 12);
	return (value);
}

char	*ft_itoa(int n)
{
	char	*value;
	int		len;
	long	ncopy;

	ncopy = n;
	if (n == -2147483648)
		return (ft_minint());
	len = ft_nbrlen(ncopy);
	value = (char *)malloc(sizeof(char) * len + 1);
	if (value == NULL)
		return (NULL);
	if (n < 0)
		ncopy = n * -1;
	value[len] = '\0';
	while (len > 0)
	{
		len--;
		value[len] = (ncopy % 10) + 48;
		ncopy = ncopy / 10;
	}
	if (n < 0)
		value[0] = '-';
	return (value);
}
