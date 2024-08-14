#include "get_next_line.h" 

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	copy = malloc(sizeof(char *) * len + 1);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*copy;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	copy = malloc(sizeof(char *) * len + 1);
	while (s1[i])
	{
		copy[j] = s1[i];
		i++;
		j++;
	}
	free (s1);
	while (s2[i])
	{
		copy[j] = s2[i];
		i++;
		j++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char		*r_line;
	char		*s_line;
	int			bites;
	int			r_length;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r_line = ft_strdup(buffer);
	s_line = NULL;
	r_length = 0;
	bites = read(fd, buffer, BUFFER_SIZE);
	buffer[bites] = '\0';
	while (bites > 0)
	{
		s_line = ft_strchr(r_line);
		if (s_line)
		{
			ft_strcpy(buffer, s_line + 1);
			break ;
		}
		r_line = ft_strjoin(r_line, buffer);
		bites = read(fd, buffer, BUFFER_SIZE);
		buffer[bites] = '\0';
	}
	if (ft_strlen(r_line) == 0)
	{
		if (r_line)
			free(r_line);
		buffer[0] = '\0';
	}
	if (r_line)
		r_length = ft_strlen(r_line) - ft_strlen(s_line) + 1;
	else
		r_length = ft_strlen(r_line);
	r_line[r_length] = '\0';
	return (r_line);
}

int	main(void)
{
	int	fd;
	int	i;
	int	limit;

	i = 0;
	limit = 2;
	fd = open("test.txt", O_RDONLY);
	while (i < limit)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}

