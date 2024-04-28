#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int colour)
{
	char	*pixel;
	
	pixel = img->mlx_addr + ( y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = colour;
}

void	isometric(t_matrix *matrix)
{
	//matrix->x = (matrix->x - matrix->y) * cos(0.523599);
	//matrix->y = (matrix->x + matrix->y) * sin(0.523599) - matrix->z;
	if (matrix)
		ft_printf("hello world");
}

