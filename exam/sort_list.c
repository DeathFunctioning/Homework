#include <unistd.h>
#include "list.h"

t_list	*sort_list(t_list *list, int (*cmp)(int, int))
{
	t_list	*temp_list;
	int		temp;

	temp_list = list;
	while (temp_list->next)
	{
		if (cmp(temp_list->data, temp_list->next->data) == 0)
		{
			temp = temp_list->data;
			temp_list->data = temp_list->next->data;
			temp_list->next->data = temp;
			temp_list = list;
		}
		else 
			temp_list = temp_list->next;

	}
	return (list);
}
