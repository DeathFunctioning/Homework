/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:22:40 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:37:11 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_copyword(char const *s, int i, char c)
{
	char	*scopy;
	int		len;
	int		i_len;
	int		j;

	j = 0;
	len = 0;
	i_len = i;
	while (s[i_len] != '\0' && s[i_len] != c)
	{
		len++;
		i_len++;
	}
	scopy = (char *)malloc(sizeof(char) * (len + 1));
	if (scopy == NULL)
		return (NULL);
	i_len = i;
	while (s[i_len] != '\0' && s[i_len] != c)
	{
		scopy[j] = s[i_len];
		i_len++;
		j++;
	}
	scopy[j] = '\0';
	return (scopy);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	j = 0;
	i = 0;
	array = (char **)malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (array == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			array[j] = ft_copyword(s, i, c);
			j++;
			i = i + (int)ft_strlen(ft_copyword(s, i, c));
		}
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	array[j] = '\0';
	return (array);
}
/*				
int	main(void)
{
	char const *s_test1 = "$$$aaaaaa";
	char const *s_test2 = "$$i$hello$world$from$above";
//	char const *s_test3 = "$helloworld$from$above";
//	char const *s_test4 = "$$$";
//	char const *s_test5 = "";
	char		**test1;
	char		**test2;
	char c = '$';
//	int i = 0;

	test1 = ft_split(s_test1, c);
	printf("test 1 = %s\n", test1[0]);
	printf("test 1 = %s\n", test1[1]);
	printf("test 1 = %s\n", test1[2]);
	printf("test 1 = %s\n", test1[3]);
	printf("test 1 = %s\n", test1[4]);
		
	test2 = ft_split(s_test2, c);
	printf("test 2 = %s\n", test2[0]);
	printf("test 2 = %s\n", test2[1]);
	printf("test 2 = %s\n", test2[2]);
	printf("test 2 = %s\n", test2[3]);
	printf("test 2 = %s\n", test2[4]);
	printf("test 2 = %s\n", test2[5]);
		
	
	printf("copy word test3 = %s\n",ft_copyword(s_test3, 1, c));
	ft_wcount(s_test1, c);
	ft_wcount(s_test2, c);
	ft_wcount(s_test3, c);
	ft_wcount(s_test4, c);
	ft_wcount(s_test5, c);
	return (0);
}*/
