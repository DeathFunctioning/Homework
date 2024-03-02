/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:37 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/02 16:48:40 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_list **list_a, t_list **list_b)
{
	t_list	*temp_list;

	temp_list = *list_a;
	*list_a = (*list_a)->next;
	temp_list->next = *list_b;
	*list_b = temp_list;
}

void	pa(t_list **list_a, t_list **list_b)
{
	push_node(list_b, list_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **list_a, t_list **list_b)
{
	push_node(list_a, list_b);
	write(1, "pb\n", 3);
}
