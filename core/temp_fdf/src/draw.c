#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int colour)
{
	char	*pixel;
	
	pixel = img->mlx_addr + ( y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = colour;
}

void	isometric(t_data *data, int y, int x)
{
	int	temp;

	temp = data->matrix[y][x].x;
	data->matrix[y][x].x = (temp - data->matrix[y][x].y) * cos(0.523599);
	data->matrix[y][x].y = (temp + data->matrix[y][x].y) * sin(0.523599) - data->matrix[y][x].z;
}


