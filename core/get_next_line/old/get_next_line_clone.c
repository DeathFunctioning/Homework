
#include "get_next_line.h"
	
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

char 	*ft_new_line_copy(t_list *lst)
{
	char	*s;
	int		len;
	t_list	*temp_node;
	int		i;

	i = 0;
	temp_node = lst;
	len = ft_get_len(lst);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (temp_node && i < 1)
	{
		s[i] = temp_node->buffer[i];
		i++;		
	}
	s[i] = '\0';
	return (s);
}

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
	//	printf("Times read = [%i]\n%s\n",count, lst->buffer);//testing
		lst->buffer[bytes] = '\0';
		if (ft_new_line(lst->buffer))
			return (ft_new_line_copy(lst));
		else 
			lst = ft_new_node(&lst);

	}
	return (lst->buffer);
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
