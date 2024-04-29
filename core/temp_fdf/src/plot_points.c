# include "fdf.h"

//gets y axis margin and boxes size 
//also gets x axis margin mainly for cantering
//need to test and add header for both functions 
void	get_margin(t_data *data)
{
	int	x_box_size;
	int	y_box_size;

	ft_printf("y_axis= %i\n", data->y_axis_len);//<-----------------------remove
	ft_printf("x_axis = %i\n", data->x_axis_len);//<-----------------------remove
	y_box_size = HEIGHT / (data->y_axis_len - 1 + 2);
	x_box_size = WIDTH / (data->x_axis_len - 1 + 2);
	ft_printf("y_box = %i\n", y_box_size);//<-----------------------remove
	ft_printf("x_box before = %i\n", x_box_size);//<-----------------------remove
	if (y_box_size < x_box_size)
		data->box_len = y_box_size;
	else
		data->box_len = x_box_size;
	data->x_margin = 10;//(WIDTH - ((data->x_axis_len - 1) * data->box_len)) / 2;
	data->y_margin = 10;//(HEIGHT - ((data->y_axis_len - 1) * data->box_len)) / 2;
	ft_printf("x_margin = %i\n", data->x_margin);//<-----------------------remove
	ft_printf("box_len = %i\n", data->box_len);//<-----------------------remove
	ft_printf("y_margin = %i\n", data->y_margin);//<-----------------------remove
	ft_printf("y_axis= %i\n", data->y_axis_len);//<-----------------------remove
}

//gets coordants for 2d grid 
void	plot_points(t_data *data)
{
	int x;
	int	y;

	get_margin(data);
	y = 0;
	while  (y < data->y_axis_len)
	{
		x = 0;
		while (x < data->x_axis_len)
		{
			
			data->matrix[y][x].x = x * 30 + WIDTH / 4;
			data->matrix[y][x].y = y * 30 + HEIGHT / 4;
			//data->matrix[y][x].x = x * data->box_len + data->x_margin;
			//data->matrix[y][x].y = y * data->box_len + data->y_margin;
			isometric(data, y, x);
			x++;
		}
		y++;
	}
}
