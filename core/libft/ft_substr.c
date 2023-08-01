/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:18:25 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/01 22:18:52 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		subs = malloc(1);
		if (subs == NULL)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	if (len > (ft_strlen(s)) - start)
		len = (ft_strlen(s) - start);
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

/*static	char	*ft_norm(char *substr)
{
	substr = (char *) malloc(sizeof(char) * 1);
	if (substr == NULL)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (len > 1024 * 1024)
		len = 1024 * 1024;
	i = 0;
	if (start >= ft_strlen(s))
	{
		return (ft_norm(substr));
	}
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

int	main(void)
{
	const char *s = "hello world";
	unsigned int start = 1;
	size_t len = 11;

	printf("test 1 = %s\n", ft_substr(s, start, len));
	free(
	return (0);
}*/
