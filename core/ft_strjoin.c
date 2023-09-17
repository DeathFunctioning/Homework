/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:32:00 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/17 15:45:46 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;

	len = (ft_strlen(s1)) + (ft_strlen(s2));
	join = (char *)malloc(sizeof(char) * len + 1);
	if (!join)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (join - len);
}

int	main(void)
{
	char	*s1 = "hello ";
	char	*s2 = "world!";
	ft_strjoin(s1, s2);
	printf("ft_strjoin = %s\n", ft_strjoin(s1, s2));
	return (0);
}
