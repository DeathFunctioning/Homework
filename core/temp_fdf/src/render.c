# include "fdf.h"

//maybe include j++ loop
void	render_background(t_data *data, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(&data->img, j++, i, colour);
		}
		i++;
	}
}

void	render_y_line(t_data *data, int x, int y)
{
	t_coords	cords;

	cords.ax = data->matrix[y][x].x;
	cords.ay = data->matrix[y][x].y;
	cords.bx = data->matrix[y + 1][x].x;
	cords.by = data->matrix[y + 1][x].y;
	cords.dx = cords.bx - cords.ax;
	cords.dy = cords.by - cords.ay;
	check_slope(data, &cords);
}

void	render_x_line(t_data *data, int x, int y)
{
	t_coords	cords;

	cords.ax = data->matrix[y][x].x;
	cords.ay = data->matrix[y][x].y;
	cords.bx = data->matrix[y][x + 1].x;
	cords.by = data->matrix[y][x + 1].y;
	cords.dx = cords.bx - cords.ax;
	cords.dy = cords.by - cords.ay;
	check_slope(data, &cords);
}

//	img_pix_put(&data->img, data->matrix[y][x].x, data->matrix[y][x].y, GREEN_COLOUR);
void	render_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->y_axis_len)
	{
		x = 0;
		while (x < data->x_axis_len)
		{
			
			if (y + 1 < data->y_axis_len)
				render_y_line(data, x, y);
			if (x + 1 < data->x_axis_len)
				render_x_line(data, x, y);
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	render_background(data, BLACK_COLOUR);
	render_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
	return (0);
}
