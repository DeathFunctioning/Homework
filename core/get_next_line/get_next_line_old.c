
#include "get_next_line.h"

t_list	*ft_split_node(t_list *lst)
{
	t_list	*new_node;


t_list	*ft_new
	
t_list	*ft_new_node(t_list **lst)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return(NULL);
	new_node.next = NULL;	
	new_node.buffer = (char *)malloc(sizeof(BUFFER_SIZE + 1));
	if (!new_node.buffer)
		return (free(new_node), NULL);
	ft_lstadd_back(lst, t_list);
	return (lst);
}

t_list	*ft_read_buffer(t_list *lst, int fd)
{
	int		bytes;

	if (!lst)
		return(NULL);
	lst.buffer = (char *)malloc(sizeof(BUFFER_SIZE + 1));
	if (!lst.buffer)
		return (free(lst), NULL);
	while ((bytes = read(fd, lst.buffer, BUFFER_SIZE + 1)) > 0);
	{
		(lst.buffer)[bytes] = '\0';
		if (!ft_new_line(lst.buffer))//small buffer case
			ft_new_node(lst);
		else if (ft_new_line(lst.buffer))//large buffer case
			ft_buffer_copy(lst);
		else
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;


	//error handling for fd and buffer size.
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!lst)
		ft_read_buffer(fd, lst)
	return (lst.buffer);//change to lsr->buffer
}

/*
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
}*/
