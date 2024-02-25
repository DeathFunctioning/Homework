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
	else
		ra(list);
}

void	sort_5(t_list **list)
{
	t_list	*stack_b;

	stack_b = NULL;
	pb(list, &stack_b);
	pb(list, &stack_b);
	if (!check_sort(list))
		sort_3(list);
	ft_print_list(*list);//test remove
	pa(list, &stack_b);//need build a sort 
	pa(list, &stack_b);
	write(1, "sort_5\n", 7);
}
