/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_wine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:24:34 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/31 16:08:02 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_save_buffer(char *buffer, t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (*buffer != '\0')
	{
		temp->buffer[i] = *buffer;
		i++;
		buffer++;
	}
	lst = temp;
}

char	*ft_split_node(t_list *lst)
{
	t_list	*node;
	int		i;
	int		j;
	char 	*newline;

	node = lst;
	j = 0;
	newline = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!newline)
		 	return	(NULL);
	while (!node)
	{
		i = 0;
		while (node->buffer[i] != '\0')
		{
			if (node->buffer[i] == '\n')
			{
				ft_save_buffer(node->buffer + i, lst);
				break ;
			}
		newline[j] = node->buffer[i];
		newline++;
		i++;
		j++;
		}
		node = node->next;
	}
	newline[j] = '\0';
	printf("newline = %s\n", newline);
	return (newline);	
}

t_list	*ft_new_node(t_list **lst)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	ft_lstadd_back(lst, new_node);
	return (new_node);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	t_list			*start;
	char			*newline;
	int				bytes;

	bytes = 1;
	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	start = lst;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, lst->buffer, BUFFER_SIZE);
		if (bytes < 0)
		   break ;	
		lst->buffer[bytes] = '\0';
		if (ft_new_line(lst->buffer) == 1)
			newline = ft_split_node(lst);
		else 
			start = ft_new_node(&lst);
	}
	return (newline);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("fd error");
		return (1);
	}

	printf("test 1 fd 1 = %s\n", get_next_line(fd));
/*	printf("test 2 fd 1 = %s\n", get_next_line(fd));
	printf("test 3 fd 1 = %s\n", get_next_line(fd));
	printf("test 4 fd 1 = %s\n", get_next_line(fd));
	printf("test 5 fd 1 = %s\n", get_next_line(fd));

	printf("test 1 fd 2 = %s\n", get_next_line(fd));
	printf("test 2 fd 2 = %s\n", get_next_line(fd));
	printf("test 3 fd 2 = %s\n", get_next_line(fd));
	printf("test 4 fd 2 = %s\n", get_next_line(fd));
	printf("test 5 fd 2 = %s\n", get_next_line(fd));

	printf("test 1 fd 3 = %s\n", get_next_line(fd));
	printf("test 2 fd 3 = %s\n", get_next_line(fd));
	printf("test 3 fd 3 = %s\n", get_next_line(fd));
	printf("test 4 fd 3 = %s\n", get_next_line(fd));
	printf("test 5 fd 3 = %s\n", get_next_line(fd));
*/	
	close(fd);
	return (0);
}
