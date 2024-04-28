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

// need to build 
// need grid spacing and x y z coords in matrix set 
// first try without iso and just get 4 x 4 grid 
// then i can look at scale and centre 
// i amlost there should be completed by the weekend 
/*void	render_line(t_data *data, int x, int y)
{



}*/

void	render_map(t_data *data)
{
	//what do i need to code here?
	//i need to just draw a simple map by 4 x 4 
	//then i can build from there
	//need to set background to black and defaualt colour green
	//to draw between points
	//if statement will draw the y axis first then the x axis if < H or W
	int	y;
	int	x;

	y = 0;
	while (y < data->y_axis_len)
	{
		x = 0;
		while (x < data->x_axis_len)
		{
			//draw down
			//if (y + 1 < data->y_axis_len)
				//render_line function(;
			//draw across ---->
			//if (x + 1 < data->x_axis_len)
				//render_line function;
			img_pix_put(&data->img, data->matrix[y][x].x, data->matrix[y][x].y, GREEN_COLOUR);
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

