#include "fdf.h"

void	check_file_name(char *file)
{
	char	*cmp;
	int		i;
	int		start;

	start = ft_strlen(file) - 4;
	i = 0;
	cmp = ".fdf";
	while (file[start])
	{
		if (file[start] != cmp[i])
		{
			ft_printf("file name error");//remove <--------------------
			exit (1);
		}
		start++;
		i++;
	}
}

int	word_count(char *s)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i] == 32)
		i++;
	while (s[i])
	{
		if (s[i] == 32)
		{
			while (s[i] == 32)
				i++;
			if (s[i] == '\0' || s[i] == '\n')
				break ;
			wc++;
		}
		else
			i++;
	}
	if (wc < 1)
	{
		ft_printf("wc error");//remove test <-------------------------------------------------------
		exit (1);
	}
	return (wc + 1);
}

void	check_map_get_x_y(t_data *data, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd error");//remov <----------------------------------------------------------------
		exit (1);
	}
	line = get_next_line(fd);
	data->x_axis_len = word_count(line);
	data->y_axis_len = 0;
	while (line)
	{
		data->y_axis_len++;
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
}

void	init(t_data	*data, char *file)
{
	check_file_name(file);
	check_map_get_x_y(data, file);
	init_matrix(data, file);
}
