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
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c) 
			return ((unsigned char *)&str[i]);
		i++;
	}
	if ((unsigned char)c == str[i])
		return ((unsigned char *)&str[i]);
	return (NULL);
}

/*int	main(void)
{
	char *str = "hello world";
	char c = 'l';

	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));

	return (0);
}*/
