
#include "get_next_line.h"

char	*ft_new_line_copy(t_list *lst)
{
	int len;
	int i;
	char *s;
	t_list	*next;

	printf("lst->buffer = %s\n", lst->buffer);//test
	i = 0;
	next = lst;
	len = ft_get_len(next);
	s = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		while (*next->buffer != '\0' && i < len) 
		{
			s[i] = *next->buffer;
			i++;
			next->buffer++;
		}
		i++;
		next->buffer++;
		next = next-> next;
	}
	s[i] = '\0';
	printf("s = %s", s);
	return (s);
}

// Creats new node in linked listed and adds to the back of the list
// This makes it easy to read through the linked list. 

t_list	*ft_new_node(t_list **lst)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return(NULL);
	new_node->next = NULL;	
	new_node->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_node->buffer)
	{
		free (new_node);
		return (NULL);
	}
	ft_lstadd_back(lst, new_node);
	return (new_node);
}

//Reads from file and copys to buffer in linked list
//Remove test!!!!!!!!!!!!
char	*ft_read_buffer(t_list *lst, int fd)
{
	int		bytes ;
	int		count = 0; //test remove
	if (!lst)
		return(NULL);
	lst->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!lst->buffer)
	{
		free (lst);
		return (NULL);
	}
	while ((bytes = read(fd, lst->buffer, BUFFER_SIZE)) > 0)
	{
		count++;//testing
	//	printf("buffer = %s\n", lst->buffer);
		lst->buffer[bytes] = '\0';
		if (!ft_new_line(lst->buffer))
			break;
		else 
			lst = ft_new_node(&lst);
	}
	return (ft_new_line_copy(lst));
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;

	lst = (t_list  *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	//error handling for fd and buffer size.
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//1st step
	return (ft_read_buffer(lst, fd));
}


int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Why want this file open");
		return (1);
	}
	printf("test1 = %s", get_next_line(fd));
	printf("\n");
	printf("test1 = %s", get_next_line(fd));
	printf("\n");
//	printf("test new line\n");
	close(fd);
	return(0);
}
