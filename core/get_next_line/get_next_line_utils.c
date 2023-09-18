/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:52:31 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/16 17:51:30 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int ft_find_nl(char *buffer)
{
	int 	i;
	char	*temp;

	i = 0;
	temp = buffer;
	while(temp[i] != '\0')
	{
		if (temp[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

//char	*gnl_strcat(
