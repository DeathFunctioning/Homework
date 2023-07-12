/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:23:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/12 19:11:41 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			while (str[i] != '\0')
			{
			str[k] = str[i];
			i++;
			k++;
			}
			str[k] = '\0';
			return (str);
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char *str = "hello world";
	char c = 'l';
	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));
	return (0);
}
