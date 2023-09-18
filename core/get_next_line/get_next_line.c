/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/09/16 17:51:40 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char	*ft_split_buffer(char *buffer, char *line, int bytes)
{
	char	*left_over;
	char	*temp_line:
	int 	i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (bytes - ft_find_nl(buffer)));
	if (!temp || !line)
		return (NULL);




}*/

char	*ft_copy_line(char *buffer, char *line, int bytes)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * bytes);
	if (!line)
		return (NULL);
	while (i < bytes)
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	line = strjoin(line, temp);
	printf("ft_copy_line_test-b = %s\n", buffer);
	printf("ft_copy_line_test-l = %s\n", line);
	printf("ft_copy_line_test-l = %s\n", temp);
	printf("ft_copy_line_test-by = %i\n", bytes);
	free(temp, buffer);
	return (line);
}

char	*get_next_line(int fd)
{
//	static char	*left_over = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	bytes = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			break;
		buffer[bytes] = '\0';
/*		if (ft_find_nl(buffer) > 0)
			left_over = ft_split_buffer(buffer, line, bytes);
		else*/
		line = ft_copy_line(buffer, line, bytes);
	}
	return (line);
}

int	main(viod)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Why want this file open");
		return (1);
	}
	printf("test1 = %s", get_next_line(fd));
	printf("test2 = %s", get_next_line(fd));
	printf("test3 = %s", get_next_line(fd));
	printf("test4 = %s", get_next_line(fd));
	close(fd);
	return (0);
}
