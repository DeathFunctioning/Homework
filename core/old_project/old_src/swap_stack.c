#include "push_swap.h"

void	swap_node(t_list **list)
{
	t_list	*temp_list;

	temp_list = (*list)->next;
	(*list)->next = temp_list->next;
	temp_list->next = *list;
	*list = temp_list;
}

void	sa(t_list **list)
{
	swap_node(list);
	write(1, "sa\n", 3);
}

void	sb(t_list **list)
{
	swap_node(list);
	write(1, "sb\n", 3);
}

void	ss(t_list **list_a, t_list **list_b)
{
	swap_node(list_a);
	swap_node(list_b);
	write(1, "ss\n", 3);
}
