# include "fdf.h"

//maybe include j++ loop
void	render_background(t_img *img, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(img, j++, i, colour);
		}
		i++;
	}
}

void	render_pixel(t_img *img, int x, int y, int colour)
{
	img_pix_put(img, x, y, colour);
}

int	render(t_data *data)
{
	render_background(&data->img, STARSHIP_COLOUR);
	render_pixel(&data->img, 100, 100, TABASCO_COLOUR);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.mlx_img, 0, 0);
	return (0);
}

