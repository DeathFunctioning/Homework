
#include "get_next_line.h"
//get to new line
int	ft_new_line(char *buffer)
{
	while(*buffer != '\0')
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

int	ft_get_len(t_list *lst)
{
	int	i;
	int len;
	t_list *next;

	next = lst;
	len = 0;
	while (next != NULL)
	{
	i = 0;
		while (next->buffer[i] != '\0')
		{
			if (next->buffer[i] == '\n')
			{
				len++;
				break;
			}	
			i++;
			len++;
		}
		if (next->buffer[i] == '\n')
			break;
		next = next->next;
	}
	printf("len = %i\n", len);//test
	return (len);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list  *temp_lst;

//		temp_lst = (t_list *)malloc(sizeof(t_list));
//        if (!lst || !new)
//                return ;
        if (!(*lst))
                *lst = new;
        else
        {
                temp_lst = *lst;
                while (temp_lst->next)
                        temp_lst = temp_lst->next;
                temp_lst->next = new;
        }
}
