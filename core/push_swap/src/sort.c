#include "push_swap.h"

void	sort_3(t_list **list)
{
	ft_print_list(*list);//test remove
	write(1, "sort_3\n", 7);
}

//create list_b here instead of main
//pb  - argc times
void	sort_5(t_list **list)
{
	t_list	*stack_b;

	stack_b = NULL;
	ft_print_list(*list);//test remove
	pb(list, &stack_b);
	pb(list, &stack_b);
	sort_3(list);
	pa(list, &stack_b);//need build a sort 
	pa(list, &stack_b);
	ft_print_list(*list);//test remove
	write(1, "sort_5\n", 7);
}
