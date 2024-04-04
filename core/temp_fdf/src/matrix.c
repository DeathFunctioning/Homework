#include "fdf.h"

int	ft_atoi_hex(char *hex)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i = 2;
	while (hex[i])
	{
		if (hex[i] >= 65 && hex[i] <= 70)
			nb = nb * 16 + hex[i] - 55;
		else if (hex[i] >= 97 && hex[i] <= 102)
			nb = nb * 16 + hex[i] - 87;
		else
			nb = nb * 16 + hex[i] - 48;
		i++;
	}
	return (nb);
}

void	assign_alt_colour(t_x_y_info *matrix, char **split_line, int len, int i)
{
	char	**data_split;

	while (i < len)
	{
		if (ft_memchr(((char *)split_line[i]), ',', ft_strlen(split_line[i])))
		{
			data_split = ft_split(split_line[i], ',');
			matrix[i].altitude = ft_atoi(data_split[0]);
			matrix[i].colour = 0x33FF66;//ft_atoi_hex(data_split[1]);
			free (data_split[0]);
			free (data_split[1]);
			free (data_split);
		}
		else
		{
			matrix[i].altitude = ft_atoi(split_line[i]);
			matrix[i].colour = 0x33FF33;
		}
		i++;
	}
}

void	init_matrix_data(t_x_y_info *matrix, int fd, int len)
{
	int		i;
	char	*line;
	char	**split_line;

	i = 0;
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	assign_alt_colour(matrix, split_line, len, i);
	//free (&line);
}

void	init_matrix(t_data *data, char *file)
{
	int	y;
	int	fd;

	y = 0;
	fd = open(file, O_RDONLY);
	data->matrix = malloc(data->y_axis_len * sizeof(t_x_y_info));
	if (!data->matrix)
	{
		ft_printf("matrix malloc error");//<--------- remove add error handler function
		exit (1);
	}
	while (y < data->y_axis_len)
	{
		data->matrix[y] = malloc(data->x_axis_len * sizeof(t_x_y_info));
		if (!data->matrix)
		{
			ft_printf("matrix malloc error");//<--------- remove add error handler function
			exit (1);
		}
		init_matrix_data(data->matrix[y], fd, data->x_axis_len);
		y++;
	}
	close (fd);
}
