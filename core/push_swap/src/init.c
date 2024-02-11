#include <push_swap.h>

//creates and add data to stack link list stru
t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
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
void	ft_print_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("%i   %i   \n", i, list->data);
		list = list->next;
		i++;
	}
	printf(" stack_a \n");
}
