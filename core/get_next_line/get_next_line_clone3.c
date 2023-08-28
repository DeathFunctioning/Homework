/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/28 21:25:32 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line_copy(t_list *lst)
{
	int		len;
	char	*s;
	char	*s2;
	char	*s_start;
	t_list	*next;

	next = lst;
	len = ft_get_len(next);
	s = (char *)malloc(sizeof(char) * (len + 1));
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	s_start = s;
	while (next != NULL)
	{
		while (*next->buffer != '\0')
		{
			*s = *next->buffer;
			if (*next->buffer == '\n')
			{
				*s = *next->buffer;
				s++;
				next->buffer++;
				while (*next->buffer != '\0')
				{
				*s2 = *next->buffer;
				s2++;
				next->buffer++;
				}
				return (s_start);
			}
			s++;
			next->buffer++;
		}
		next = next->next;
	}
	*s2 = '\0';
	lst->buffer = s2;
	*s = '\0';
	return (s_start);
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
	t_list	*new;
	t_list  *new_node;

	new = lst;
	if (!lst)
		return (NULL);
	lst->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!lst->buffer)
	{
		free (lst);
		return (NULL);
	}
	while ((bytes = read(fd, new->buffer, 1)) > 0)
	{
		lst->buffer[bytes] = '\0';
		if (ft_new_line(new->buffer) == 1)
			break;
		else
		{	
			new_node = ft_new_node(&lst);
			if (!new_node)
				return (NULL);
			new = new_node;
		}
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
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read_buffer(lst, fd);
	return (s);
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
	printf("test2 = %s", get_next_line(fd));
	printf("test3 = %s", get_next_line(fd));
//	printf("test4 = %s", get_next_line(fd));
//	printf("test new line\n");
	close(fd);
	return (0);
}*/
