/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:37:57 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/25 15:17:12 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line_copy(t_list *lst)
{
	int		len;
	int		i;
	int		j;
	char	*s;
	char	*s2;
	t_list	*next;

	printf("lst->buffer = %s", lst->buffer);//test
	i = 0;
	j = 0;
	next = lst;
	len = ft_get_len(lst);
	s = (char *)malloc(sizeof(char) * (len + 1));
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		while (*next->buffer != '\0' && i < len) 
		{
			s[i] = *next->buffer;
		//	*next->buffer = '\0';
			if (*next->buffer == '\n')
			{
				s[i] = *next->buffer;
				i++;
				next->buffer++;
				while (*next->buffer != '\0')
				{
					*s2 = *next->buffer;
					s2++;
					next->buffer++;
				}
				*s2 = '\0';
				next->buffer = s2;
				s[i] = '\0';
				printf("s2 = %s", s2);
				return (s);
			}
			i++;
			next->buffer++;
		}
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
		return (NULL);
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
	int	bytes ;
	int	count = 0; //test remove
	if (!lst)
		return (NULL);
	lst->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!lst->buffer)
	{
		free (lst);
		return (NULL);
	}
	while ((bytes = read(fd, lst->buffer, BUFFER_SIZE)) > 0)
	{
		count++;//testing
		printf("buffer = %s\n", lst->buffer);
		lst->buffer[bytes] = '\0';
		if (ft_new_line(lst->buffer) == 1)
			break;
		else 
			lst = ft_new_node(&lst);
	}
	return (ft_new_line_copy(lst));
}


char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*s;

	lst = (t_list  *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	//error handling for fd and buffer size.
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//1st step
	s = ft_read_buffer(lst, fd);
	//lst = ft_new_start(lst);
	return (s);
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
	printf("test2 = %s", get_next_line(fd));
//	printf("test3 = %s", get_next_line(fd));
//	printf("test4 = %s", get_next_line(fd));
//	printf("test new line\n");
	close(fd);
	return (0);
}
