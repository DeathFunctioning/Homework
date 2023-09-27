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

/*char	*ft_left(char **left, char *line)
{
	int	nl;
	int	i;
	int	j;

	i = 0;
	j = 0;
	nl = ft_find_nl(*left);
	line = (char *)malloc(sizeof(char) * (nl + 1));
	if (!line)
		return(NULL);//-- may need to free here
	while(i < nl)
	{
		line[i] = *left[i];
	//	left[i] = '\0';
		i++;
	}
	line[i] = '\0';
	i++;
	while (*left[i])
	{
		*left[j] =  *left[i];
	//	left[i] = '\0';
		i++;
		j++;
	}
	return (line);
}*/

char	*ft_line(char *left, char *line)
{
	int		nl;
	int		i;
	char	*temp;

	i = 0;
	nl = ft_find_nl(left);
	temp = (char *)malloc(sizeof(char) * (nl + 1));
	if (!temp)
		return(NULL);//-- may need to free here
	while (i < nl)
	{
		temp[i] = left[i];
		i++;
	}
	temp[i] = '\0';
//	printf("test point line = %s\n", line);//
//	printf("test point temp = %s\n", temp);//
//	printf("test point left = %s\n", left);//
	if (!line)
		line = strdup("");
	line = ft_strjoin(line, temp);
	free (temp);
	return (line);
}

char	*ft_left(char *left)
{
	int		nl;
	int		i;
	char	*temp;

	nl = ft_find_nl(left);
	i = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(left) - nl + 1));
	if (!temp)
		return(NULL);//-- may need to free here
	while (left[i])
	{
		temp[i] = left[nl + 1 + i];
		i++;
	}
	temp[i] = '\0';
	left = ft_strjoin("", temp);
	free (temp);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		*line = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_find_nl(left) > 0)
	{
		line = ft_line(left, line);
		left = ft_left(left);
		return (line);
	}
	/*if (ft_find_nl(left) > 0)
	{
		line = ft_left(&left, line);
		return(line);
	}*/
	while(bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (!left)
			left = strdup("");//
		left = ft_strjoin(left, buffer);
		if (ft_find_nl(left) > 0)
		{
			line = ft_line(left, line);
			left = ft_left(left);
			return (line);
		}
	}
	free(line);
	return (left);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Why want this file open");
		return (1);
	}
	printf("test 1 = %s\n", get_next_line(fd));
	printf("test 2 = %s\n", get_next_line(fd));
	printf("test 3 = %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
