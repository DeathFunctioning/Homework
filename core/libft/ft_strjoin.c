/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:35:31 by tbaker            #+#    #+#             */
/*   Updated: 2023/06/07 09:07:05 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *scopy, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		scopy[i] = str[i];
		i++;
	}
	scopy[i] = '\0';
	return (scopy);
}

char	*ft_strcat(char *scopy, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (scopy[i] != '\0')
	{
		i++;
	}
	while (str[j] != '\0')
	{
		scopy[i] = str[j];
		i++;
		j++;
	}
	scopy[i] = '\0';
	return (scopy);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		new_strl;
	int		i;
	char	*scopy;

	i = 0;
	if (size == 0)
		return (scopy = (char *)malloc(sizeof(char) * 1));
	new_strl = ft_strlen(sep) * (size - 1);
	while (i < size)
	{
		new_strl = new_strl + ft_strlen(strs[i]);
		i++;
	}
	scopy = (char *)malloc(sizeof(char) * new_strl + 1);
	if (scopy == NULL)
		return (NULL);
	ft_strcpy(scopy, strs[0]);
	i = 1;
	while (i < size)
	{
		ft_strcat(scopy, sep);
		ft_strcat(scopy, strs[i]);
		i++;
	}
	return (scopy);
}
