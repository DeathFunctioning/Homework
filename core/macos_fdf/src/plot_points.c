/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:40:34 by tbaker            #+#    #+#             */
/*   Updated: 2024/06/14 19:08:48 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_cell_size(t_data *data)
{
	float	cell_size;
	float	cell_width;
	float	cell_height;

	cell_width = (float)WIDTH / (data->x_axis_len - 1 + 2);
	cell_height = (float)HEIGHT / (data->y_axis_len - 1 + 2);
	if (cell_width < cell_height)
		cell_size = cell_width / 1;
	else
		cell_size = cell_height / 1;
	return ((int)cell_size);
}

void	plot_points(t_data *data)
{
	int		x;
	int		y;
	float	cell_size;

	cell_size = get_cell_size(data);
	y = 0;
	while (y < data->y_axis_len)
	{
		x = 0;
		while (x < data->x_axis_len)
		{
			data->matrix[y][x].x = x;
			data->matrix[y][x].y = y;
			data->matrix[y][x].x *= cell_size;
			data->matrix[y][x].y *= cell_size;
			isometric(data, y, x);
			data->matrix[y][x].x += WIDTH / 2;
			data->matrix[y][x].y += HEIGHT / 2 - 500;
			x++;
		}
		y++;
	}
}
