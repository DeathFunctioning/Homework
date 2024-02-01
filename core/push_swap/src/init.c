#include <push_swap.h>

//creates and add data to stack link list stru
t_stack *create_stack(int data)
{
	t_stack	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}


