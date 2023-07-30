/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:08 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:46:40 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*scopy;
	unsigned int	i;

	i = 0;
	scopy = ft_strdup(s);
	while (s[i] != '\0')
	{
		scopy[i] = f(i, s[i]);
		i++;
	}
	scopy[i] = '\0';
	return (scopy);
}
/*
char	f(unsigned int i, char c)
{
	char fstr = c + 1;
	return (fstr);
}

int main(void)
{
	const char *s = "123456";
	char *test;

	test = ft_strmapi(s, f);
	printf("My 1st test = %s\n", test);
	return (0);
}*/
