/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:37:35 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:44:39 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	count;
	int	nb;

	nb = n;
	count = 1;
	if (n < 0)
	{
		nb = n * -1;
		count++;
	}
	while (nb > 9) 
	{
		nb = nb / 10;
		count++;
	}
	printf("count = %d\n", count);
	return (count);
}

char	*ft_itoa(int n)
{
	char	*value;
	int		len;
	int		ncopy;

	ncopy = n;
	len = ft_nbrlen(n);
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
/*
int	main(void)
{
	int	n_test1 = 1;
	int	n_test2 = -123425;
	int	n_test3 = +12344667;
	int	n_test4 = 12344667;
	int	n_test5 = 12344667;

	printf("test 1 = %s\n", ft_itoa(n_test1));
	printf("test 2 = %s\n", ft_itoa(n_test2));
	printf("test 3 = %s\n", ft_itoa(n_test3));
	printf("test 4 = %s\n", ft_itoa(n_test4));
	printf("test 5 = %s\n", ft_itoa(n_test5));
	return (0);
}*/
