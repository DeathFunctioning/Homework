/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:51:54 by tbaker            #+#    #+#             */
/*   Updated: 2024/05/19 18:55:35 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//check print statements 
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
			ft_printf("file name error\n");
			exit (1);
		}
		start++;
		i++;
	}
}

//too many lines easy fix can send both i and wc as int 0
int	word_count(char *s, int i)
{
	int	wc;

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
		ft_printf("wc error\n");
		exit (1);
	}
	return (wc + 1);
}

void	check_map_get_x_y(t_data *data, char *file)
{
	char		*line;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd error\n");
		exit (1);
	}
	line = get_next_line(fd);
	data->x_axis_len = word_count(line, 0);
	data->y_axis_len = 0;
	while (line)
	{
		data->y_axis_len++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
}

//need to distroy of free iomage and addr when close 
//window need to create function for closing window 
void	init(t_data	*data, char *file)
{
	check_file_name(file);
	check_map_get_x_y(data, file);
	init_matrix(data, file);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("mlx_init error");
		exit (1);
	}
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fdf");
	if (!data->mlx_win)
	{
		ft_printf("mlx_init error");
		free (data->mlx_win);
		exit (1);
	}
	data->img.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.mlx_addr = mlx_get_data_addr(data->img.mlx_img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
}
