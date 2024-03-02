/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:05 by tbaker            #+#    #+#             */
/*   Updated: 2024/03/02 16:48:11 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));//changed from new to *new maybe just t_list
	if (!new)
		return (NULL);
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

//need to remove
void	ft_print_list(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	while (stack_a && stack_b)
	{
		printf("Idx = %i   %i   %i   idx_v_a = %i\n", stack_a->idx_p, stack_a->data, stack_b->data, stack_a->idx_v);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
		i++;
	}
	while (stack_a)
	{
		printf("Idx = %i   %i   X   ind_v_a = %i\n", stack_a->idx_p, stack_a->data, stack_a->idx_v);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("B Idx ignore = %i   X   %i\n", i, stack_b->data);
		stack_b = stack_b->next;
	}
	printf("       stack_a  stack_b \n");
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
	printf("list length = %i\n", lst_len);//test remove 
	return (lst_len);
}









































