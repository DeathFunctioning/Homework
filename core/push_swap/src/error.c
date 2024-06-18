/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:47:45 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/09 18:43:45 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **list)
{
	t_list	*next_node;

	while (*list)
	{
		next_node = (*list)->next;
		free(*list);
		*list = next_node;
	}
	*list = NULL;
	next_node = NULL;
}

void	error(t_list **list)
{
	free_list(list);
	write (2, "Error\n", 6);
	exit (-1);
}

int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '-' || s[i] == '+') && s[i + 1])
		i++;
	while (s[i])
	{
		if (!(s[i] >= 48 && s[i] <= 57))
			return (-1);
		i++;
	}
	return (0);
}

int	check_double(int nb, t_list **list)
{
	t_list	*temp_list;
	int		flag;

	flag = 0;
	temp_list = *list;
	while (temp_list)
	{
		if (nb == temp_list->data)
			flag++;
		if (flag == 2)
			return (-1);
		temp_list = temp_list->next;
	}
	return (0);
}

int	check_sort(t_list **list)
{
	t_list	*temp_list;

	temp_list = *list;
	while (temp_list->next)
	{
		if (temp_list->data > temp_list->next->data)
			return (0);
		temp_list = temp_list->next;
	}
	return (1);
}
