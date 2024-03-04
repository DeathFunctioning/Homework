/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:05 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/02 16:58:18 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//changed from new to *new maybe just t_list mallac issues 
t_list	*ft_lstnew(t_list **list, int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		error (list);
	new->data = data;
	new->next = NULL;
	new->idx_p = 0;
	new->idx_v = -1;
	return (new);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*temp_list;

	if (*list)
	{
		temp_list = *list;
		while (temp_list->next)
			temp_list = temp_list->next;
		temp_list->next = new;
	}
	else
		*list = new;
}

//returns list lenght/size && adds current lst position from head to tail
int	lst_size_index(t_list **list)
{
	t_list	*temp_list;
	int		lst_len;

	lst_len = 0;
	temp_list = *list;
	while (temp_list)
	{
		temp_list->idx_p = lst_len;
		lst_len++;
		temp_list = temp_list->next;
	}
	return (lst_len);
}

void	index_assign_value(t_list **list, int i, int min)
{
	t_list	*temp_list;

	temp_list = *list;
	while (temp_list)
	{
		if (temp_list->data == min && temp_list->idx_v == -1)
			temp_list->idx_v = i;
		temp_list = temp_list->next;
	}
}

void	index_value(t_list **list, int len, int min)
{
	t_list	*temp_list;
	int		i;

	i = 0;
	temp_list = *list;
	while (i < len)
	{
		while (temp_list)
		{
			if (temp_list->data < min && temp_list->idx_v == -1)
				min = temp_list->data;
			temp_list = temp_list->next;
		}
		index_assign_value(list, i, min);
		temp_list = *list;
		while (temp_list)
		{
			if (temp_list->data > min && temp_list->idx_v == -1)
				min = temp_list->data;
			temp_list = temp_list->next;
		}
		temp_list = *list;
		i++;
	}
}
