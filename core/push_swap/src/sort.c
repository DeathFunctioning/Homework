/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:45:11 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/02 17:11:21 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->data;
	b = (*list)->next->data;
	c = (*list)->next->next->data;
	if (a < b && a > c)
		rra(list);
	else if(a < b && b > c)
	{
		sa(list);
		ra(list);
	}
	else if (a > b && a < c)
		sa(list);
	else if (a > b && b > c)
	{
		ra(list);
		sa(list);
	}
	else if (a > b && b < c)
		ra(list);
}

void	sort_5(t_list **list_a, t_list **list_b)
{
	//pb_min works for 5 now to sort if 5 and pa till stack_b empty should i build sort 2/swap if > or try in corperate into swap 3
	//if i do this i can sort 6 in this sort do i want to add complexity to improve effectance in steaD OF JUST ra 
	//list_a i could rra if idx_v is at the bottom half of the list but i think sorting 5 or 6 lioke this is below the
	//threshold for operations
	ft_print_list(*list_a, *list_b);//test remove
	pb_min_values(list_a, list_b);
	sort_3(list_a);
	ft_print_list(*list_a, *list_b);//test remove
	if ((*list_b)->data < (*list_b)->next->data)
		sb(list_b);
	pa(list_a, list_b);
	pa(list_a, list_b);
	ft_print_list(*list_a, *list_b);//test remove
	write(1, "sort_5\n", 7);//test remove
}

void	pb_min_values(t_list **list_a, t_list **list_b)
{
	int	len;
	int	i;
	t_list	*temp_list;

	temp_list = *list_a;
	len = lst_size_index(list_a);
	i = 0;
	while (i < len - 3)
	{
		temp_list = *list_a;
		if (temp_list->idx_v < len - 3)
		{
			pb(list_a, list_b);
			i++;
		}
		else
			ra(list_a);
	}
}

void	index_value(t_list **list, int len)
{
	t_list	*temp_list;
	int		i;
	int		min;

	i = 0;
	temp_list = *list;
	min = temp_list->data;
	//need to build a functoin that will find the max value and then asign it the index value of len - 1 then i could maybe update my conditional loops to include max if to clean up this mess of code. 
	while (i < len)
	{
		while(temp_list)
		{
			if (temp_list->data < min && temp_list->idx_v == -1)
				 min = temp_list->data;
			temp_list = temp_list->next;
		}
		// can build ft_that sends i vaule min and list added value to node correct node 
		temp_list = *list;
		while(temp_list)
		{
			if (temp_list->data == min && temp_list->idx_v == -1)
				temp_list->idx_v = i;
			temp_list = temp_list->next;
		}
		temp_list = *list;
		while(temp_list)
		{
			if (temp_list->data > min && temp_list->idx_v == -1)
				min = temp_list->data;
			temp_list = temp_list->next;
		}
		temp_list = *list;
		i++;
	}
}

