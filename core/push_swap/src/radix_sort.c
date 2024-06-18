/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:07:42 by tbaker            #+#    #+#             */
/*   Updated: 2024/06/18 15:07:48 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **list_a, t_list **list_b)
{
	int	i;
	int	j;
	int	size;
	int	num;

	i = 0;
	size = lst_size_index(list_a);
	while (1)
	{
		if (check_sort(list_a) != 0)
			break ;
		j = 0;
		while (j < size)
		{
			num = (*list_a)->idx_v;
			if (((num >> i) & 1) == 1)
				ra(list_a);
			else
				pb(list_a, list_b);
			j++;
		}
		pa_till_stack_b_empty(list_a, list_b);
		i++;
	}
}
