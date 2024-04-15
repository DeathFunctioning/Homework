#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int colour)
{
	char	*pixel;
	
	pixel = img->mlx_addr + ( y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = colour;
}
