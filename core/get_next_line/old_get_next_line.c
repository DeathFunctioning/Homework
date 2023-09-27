/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/24 18:55:52 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_end_line(char *line, char *buffer)
{
	char	*temp;
//	char	*temp2;
	int		end;
	int		i;

	i = 0;
	end = ft_find_nl(buffer) + 1;
	temp = (char *)malloc(sizeof(char) * (end + 1));
	if (!temp)
		return (NULL);
	while (i < end)//strdup?
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
//	temp2 = ft_strjoin(line, temp);
//	return (temp2);
	return (ft_strjoin(line, temp));
}

char	*ft_buffer_next(char *buffer)
{
	char	*temp;
	int		start;
	int		i;

	i = 0;
	start = ft_find_nl(buffer) + 1;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - start + 1));
	if (!temp)
		return (NULL);
	while (buffer[start] != '\0')
	{
		temp[i] = buffer[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		*line = NULL;
	char		buffer[BUFFER_SIZE + 1];
	
	if (left)
	{
		if (ft_find_nl(left) > 0);
		{
			line = ft_left(&left, line)
		}
		else
		{

		}
	}








/*
char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line = NULL;
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_find_nl(left) > 0)
	{
		line = ft_end_line(line, left);
		left = ft_buffer_next(left);
		return (line);
	}
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (left)
			left = ft_strjoin(left, buffer);
		if (ft_find_nl(buffer) > 0)
		{
			line = ft_end_line(line, buffer);
			left = ft_buffer_next(buffer);
			break;
		}
		line = ft_strjoin(line, buffer);
		if (bytes == 0)
			break;
	}
	return (line);
}*/

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Why want this file open");
		return (1);
	}
	printf("test1 = \n%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
