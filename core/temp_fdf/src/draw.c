#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int colour)
{
	char	*pixel;
	
	pixel = img->mlx_addr + ( y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = colour;
}

void	isometric(t_matrix *matrix)
{
	matrix->x = (matrix->x - matrix->y) * cos(angle);
	matrix->y = (matrix->x + matrix->y) * sin(angle) - matrix->z;
}
