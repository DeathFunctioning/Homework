/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:40:34 by tbaker            #+#    #+#             */
/*   Updated: 2024/05/19 19:04:27 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//gets y axis margin and boxes size 
//also gets x axis margin mainly for cantering
//need to test and add header for both functions 
void	get_margin(t_data *data)
{
	int	x_box_size;
	int	y_box_size;

	y_box_size = HEIGHT / (data->y_axis_len - 1 + 2);
	x_box_size = WIDTH / (data->x_axis_len - 1 + 2);
	if (y_box_size < x_box_size)
		data->box_len = y_box_size;
	else
		data->box_len = x_box_size;
	data->x_margin = 10;//(WIDTH - ((data->x_axis_len - 1) * data->box_len)) / 2;
	data->y_margin = 10;//(HEIGHT - ((data->y_axis_len - 1) * data->box_len)) / 2;
}

int	get_cell_size(t_data *data)
{
	float	cell_size;
	float	cell_width;
	float	cell_height;

	cell_width = (float)WIDTH / (data->x_axis_len);
	cell_height = (float)HEIGHT / (data->y_axis_len);
	if (cell_width < cell_height)
		cell_size = cell_width;
	else
		cell_size = cell_height;
	return ((int)cell_size);
}

//need to fix iso and added scale and padding and to create
//Works for 2d grid 
//need to remove margin function 
//colour interpolation done 
//tonigh or tommorow fix iso metric diaSPLAY 
void	plot_points(t_data *data)
{
	int		x;
	int		y;
	float	cell_size;

	cell_size = 45;// get_cell_size(data); 
	ft_printf("cell size= %i\n", cell_size);//<-----------------------remove
	get_margin(data);
	y = 0;
	while (y < data->y_axis_len)
	{
		x = 0;
		while (x < data->x_axis_len)
		{
			data->matrix[y][x].x = x * cell_size;
			data->matrix[y][x].y = y * cell_size;
			isometric(data, y, x);
			data->matrix[y][x].x += WIDTH / 3;
			data->matrix[y][x].y += HEIGHT / 3;
			x++;
		}
		y++;
	}
}
