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

	sort_3(list_a);
	ft_print_list(*list_a, *list_b);//test remove
	pb_min_values(list_a, list_b);
	sort_3(list_a);
	ft_print_list(*list_a, *list_b);//test remove
	pa(list_a, list_b);
	pa(list_a, list_b);
	ft_print_list(*list_a, *list_b);//test remove
	write(1, "sort_5\n", 7);//test remove
}

void	pb_min_values(t_list **list_a, t_list **list_b)
{
	int	len;
	int	limit;

	len = lst_size_index(list_a);
	limit = len - 3;
	//remove and replace with pb relative values < limit so for sort 4 i would only relative value 0 if sort 5 0 && 1 values need to be pushed to stack b then swap them if not sorted then do sort 3 the pa whats left in b easy the hard part is i know have to index values 
	while (limit--)
		pb(list_a, list_b);
}

void	index_value(t_list **list, int len)
{
	t_list	*temp_list;
	int		i;
	int		min;

	i = 0;
	temp_list = *list;
	//need to build a functoin that will find the max value and then asign it the index value of len - 1 then i could maybe update my conditional loops to include max if to clean up this mess of code. 
	while (i < len)
	{
		min = temp_list->data;
		while(temp_list)
		{
			if (i == (len - 1) && temp_list->idx_v == -1)
				 min = temp_list->data;
			if (temp_list->data < min && temp_list->idx_v == -1)
				 min = temp_list->data;
			temp_list = temp_list->next;
		}
		// can build ft_that sends i vaule min and list added value to node correct node 
		temp_list = *list;
		while(temp_list)
		{
			if (temp_list->data == min)
				temp_list->idx_v = i;
			temp_list = temp_list->next;
		}
		temp_list = *list;
		i++;
	}
}




