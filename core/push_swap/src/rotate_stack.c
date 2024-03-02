/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:49:15 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/02 16:58:40 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_list **list)
{
	t_list	*temp_list;
	t_list	*swap_list;

	swap_list = *list;
	temp_list = *list;
	*list = (*list)->next;
	while (temp_list->next)
		temp_list = temp_list->next;
	swap_list->next = NULL;
	temp_list->next = swap_list;
}

void	ra(t_list **list)
{
	rotate_list(list);
	write(1, "ra\n", 3);
}

void	rb(t_list **list)
{
	rotate_list(list);
	write(1, "rb\n", 3);
}

void	rr(t_list **list_a, t_list **list_b)
{
	rotate_list(list_a);
	rotate_list(list_b);
	write(1, "rr\n", 3);
}
