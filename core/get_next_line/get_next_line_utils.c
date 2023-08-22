
#include "get_next_line.h"
//get to new line
char	*ft_new_line(char *buffer)
{
	while(!(*buffer))
	{
		if (*buffer == '\n')
			return (buffer);
		buffer++;
	}
	return (NULL);
}

int	ft_get_len(t_list *lst)
{
	int	i;
	int len;
	t_list *next;

	next = lst;
	len = 0;
	while (next)
	{
	i = 0;
		while (next->buffer[i] != '\n' && next->buffer[i] != '\0')
		{	
			i++;
			len++;
		}
		if (next->buffer[i] == '\n')
		{
			len++;
			break;
		}
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
