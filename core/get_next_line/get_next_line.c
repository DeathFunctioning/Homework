/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/10/07 17:56:30 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

char	*ft_split_left(char **left)
{
	char	*temp;
	int		i;
	char	*new_left;

	if (!*left)
		return (NULL);
	i = 0;
	while ((*left)[i] != '\0' && (*left)[i] != '\n')
		i++;
	if ((*left)[i] == '\n')
	{
		i++;
		temp = ft_strndup(*left, i);
		new_left = ft_strndup(&(*left)[i], ft_strlen(&(*left)[i]));
		ft_free(left);
		*left = new_left;
	}
	else
	{
		temp = ft_strndup(*left, i);
		ft_free(left);
	}
	return (temp);
}

char	*ft_read(char **left, int fd)
{
	int		bytes;
	char	*buffer;
	char	*temp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (1)
	{
		if (ft_strchr(*left, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			if (bytes == -1)
				ft_free(left);
			break ;
		}
		buffer[bytes] = '\0';
		temp = *left;
		*left = ft_strjoin(temp, buffer);
		ft_free(&temp);
		if (ft_strchr(*left, '\n'))
			break ;
	}
	ft_free(&buffer);
	if (*left && **left)
		return (ft_split_left(left));
	ft_free(left);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (ft_read(&left, fd));
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Why want this file open");
		return (1);
	}
	printf("test 1 = %s", get_next_line(fd));
	printf("test 2 = %s", get_next_line(fd));
	printf("test 3 = %s", get_next_line(fd));
	printf("test 4 = %s", get_next_line(fd));
	printf("test 5 = %s", get_next_line(fd));
	printf("test 6 = %s", get_next_line(fd));
	printf("test 7 = %s", get_next_line(fd));
	printf("test 8 = %s", get_next_line(fd));
	printf("test 9 = %s", get_next_line(fd));
	printf("test 10 = %s", get_next_line(fd));
	close(fd);
	return (0);
}*/
