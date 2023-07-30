/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:18:25 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/30 18:22:33 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	substr = (char *) malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*int	main(void)
{
	const char *s = "hello world";
	unsigned int start = 1;
	size_t len = 11;

	printf("test 1 = %s\n", ft_substr(s, start, len));
	free(
	return (0);
}*/
