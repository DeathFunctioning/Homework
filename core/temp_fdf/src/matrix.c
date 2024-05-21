/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:41:31 by tbaker            #+#    #+#             */
/*   Updated: 2024/05/19 18:42:54 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

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

void	assign_alt_colour(t_matrix *matrix, char **split_line, int len, int i)
{
	char	**data_split;

	while (i < len)
	{
		if (ft_memchr(((char *)split_line[i]), ',', ft_strlen(split_line[i])))
		{
			data_split = ft_split(split_line[i], ',');
			matrix[i].z = ft_atoi(data_split[0]);
			matrix[i].colour = ft_atoi_hex(data_split[1]);
			free_array(data_split);
		}
		else
		{
			matrix[i].z = ft_atoi(split_line[i]);
			matrix[i].colour = 0x33FF33;
		}
		i++;
	}
}

void	init_matrix_data(t_matrix *matrix, int fd, int len)
{
	char	*line;
	char	**split_line;

	line = get_next_line(fd);
	if (line)
	{
		split_line = ft_split(line, ' ');
		free (line);
		if (split_line)
		{
			assign_alt_colour(matrix, split_line, len, 0);
			free_array(split_line);
		}
	}
}

void	init_matrix(t_data *data, char *file)
{
	int		y;
	int		fd;

	y = 0;
	fd = open(file, O_RDONLY);
	data->matrix = malloc(data->y_axis_len * sizeof(t_matrix));
	if (!data->matrix)
	{
		ft_printf("matrix malloc error\n");
		exit (1);
	}
	while (y < data->y_axis_len)
	{
		data->matrix[y] = malloc(data->x_axis_len * sizeof(t_matrix));
		if (!data->matrix)
		{
			free_matrix(data->matrix, y);
			ft_printf("matrix malloc error\n");
			exit (1);
		}
		init_matrix_data(data->matrix[y], fd, data->x_axis_len);
		y++;
	}
	close (fd);
	plot_points(data);
}
