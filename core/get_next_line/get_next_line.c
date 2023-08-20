
#include "get_next_line.h"

t_list	*ft_new_node(t_list *lst, int fd)
{

}

char	*get_next_line(int fd)
{
	static t_size	*lst = NULL;


	//error handling for fd and buffer size.
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!lst == NULL)
		ft_new_node(fd, lst)
	return (line);
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
