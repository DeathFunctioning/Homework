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
	write(1, "pb\n", 3);
}

void	pb(t_list **list_a, t_list **list_b)
{
	push_node(list_a, list_b);
	write(1, "pb\n", 3);
}
