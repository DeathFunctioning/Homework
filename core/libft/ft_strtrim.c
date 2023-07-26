/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:18:01 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:18:07 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_notrim(char const *s1)
{
	char	*trimstr;
	size_t	slen;

	slen = ft_strlen(s1);
	trimstr = (char *)malloc(sizeof(char) * (slen + 1));
	if (trimstr == NULL)
		return (NULL);
	ft_memcpy(trimstr, s1, slen);
	trimstr[slen] = '\0';
	return (trimstr);
}

char	*ft_trimstart(char const *s1, const char *set)
{
	char	*trimstr;
	size_t	setlen;
	size_t	slen;

	setlen = ft_strlen(set);
	slen = ft_strlen(s1);
	trimstr = (char *) malloc(sizeof(char) * (slen - setlen + 1));
	if (trimstr == NULL)
		return (NULL);
	ft_memcpy (trimstr, s1 + setlen, slen - setlen);
	trimstr[slen - setlen] = '\0';
	return (trimstr);
}

char	*ft_trimend(char const *s1, const char *set)
{
	char	*trimstr;
	size_t	setlen;
	size_t	slen;

	setlen = ft_strlen(set);
	slen = ft_strlen(s1);
	trimstr = (char *) malloc(sizeof(char) * (slen - setlen + 1));
	if (trimstr == NULL)
		return (NULL);
	ft_memcpy (trimstr, s1, slen - setlen);
	trimstr[slen - setlen] = '\0';
	return (trimstr);
}

char	*ft_trimboth(char const *s1, const char *set)
{
	char	*trimstr;
	size_t	setlen;
	size_t	slen;

	setlen = ft_strlen(set);
	slen = ft_strlen(s1);
	trimstr = (char *) malloc(sizeof(char) * (slen - (2 * setlen) + 1));
	if (trimstr == NULL)
		return (NULL);
	ft_memcpy (trimstr, s1 + setlen, slen - setlen);
	trimstr[slen - (2 * setlen)] = '\0';
	return (trimstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstr;
	size_t	setlen;
	size_t	slen;
	int		end;
	int		start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	setlen = ft_strlen(set);
	slen = ft_strlen(s1);
	end = ft_strncmp(s1 + (slen - setlen), set, setlen); 
	start = ft_strncmp(s1, set, setlen); 
	if (start != 0 && end != 0)
		trimstr = ft_notrim(s1);
	else if (start == 0 && end != 0)
		trimstr = ft_trimstart(s1, set);
	else if (start != 0 && end == 0)
		trimstr = ft_trimend(s1, set);
	else
		trimstr = ft_trimboth(s1, set);
	return (trimstr);
}
/*
int	main(void)
{
	char const *s1_test1 = "$$$hello world$$$";
	char const *s1_test2 = "hello world$$$";
	char const *s1_test3 = "$$$hello world";
	char const *s1_test4 = "hello $$$ world$$$";
	char const *s1_test5 = "hello world";
	char const *set = "$$$";
	printf("test 1 = %s\n", ft_strtrim(s1_test1, set));
	printf("test 2 = %s\n", ft_strtrim(s1_test2, set));
	printf("test 3 = %s\n", ft_strtrim(s1_test3, set));
	printf("test 4 = %s\n", ft_strtrim(s1_test4, set));
	printf("test 5 = %s\n", ft_strtrim(s1_test5, set));
	return (0);
}*/
