#include "push_swap.h"

void	reverse_rotate_list(t_list **list)
{
	t_list	*temp_list;
	t_list	*last_list;

	temp_list = *list;
	while (temp_list->next->next)
		temp_list = temp_list->next;
	last_list = temp_list->next;
	temp_list->next = NULL;
	last_list->next = *list;
	*list = last_list;
}

void	rra(t_list **list)
{
	reverse_rotate_list(list);
	write(1, "rra\n", 4);
}

void	rrb(t_list **list)
{
	reverse_rotate_list(list);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	reverse_rotate_list(list_a);
	reverse_rotate_list(list_b);
	write(1, "rrr\n", 4);
}
