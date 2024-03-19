/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:08 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/19 16:58:52 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*scopy;
	unsigned int	i;

	i = 0;
	scopy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (scopy == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		scopy[i] = f(i, s[i]);
		i++;
	}
	scopy[i] = '\0';
	return (scopy);
}
