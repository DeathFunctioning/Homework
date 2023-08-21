
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

t_list	*ft_read_buffer(t_list *lst, int fd)
{
	int		bytes = 1;
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
		count++;
		printf("Times read = [%i]\n%s\n",count, lst->buffer);
		lst->buffer[bytes] = '\0';
		lst = ft_new_node(&lst);
	}
	return (lst);
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
	ft_read_buffer(lst, fd);
	return ("test");//change to lsr->buffer
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
	printf("test new line\n");
	printf("test1 = %s", get_next_line(fd));
	printf("test new line\n");
	close(fd);
	return(0);
}
