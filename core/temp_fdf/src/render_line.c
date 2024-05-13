#include "fdf.h"

void	slope_less_than_one(t_data *data, t_coords *cords)
{
	int	i;
	int	p;

	i = -1;
	p = 2 * abs(cords->dy) - abs(cords->dx);
	while (++i < abs(cords->dx))
	{
		if (cords->dx < 0)
			cords->cx -= 1;
		else
			cords->cx += 1;
		if (p < 0)
			p = p + 2 * abs(cords->dy);
		else
		{
			if (cords->dy < 0)
				cords->cy -= 1;
			else
				cords->cy += 1;
			p = p + 2 * abs(cords->dy) - 2 * abs(cords->dx);
		}
		render_grad_line(cords, abs(cords->dx), i);
		img_pix_put(&data->img, cords->cx, cords->cy, cords->cc);
	}
}
//instead of img_pix_put her i can send it to another fuynction that sets the colour
//and put the image for both of the slopes this is all that needs to be done here 
void	slope_greater_than_one(t_data *data, t_coords *cords)
{
	int	i;
	int	p;

	i = -1;
	p = 2 * abs(cords->dx) - abs(cords->dy);
	while (++i < abs(cords->dy))
	{
		if (cords->dy < 0)
			cords->cy -= 1;
		else
			cords->cy += 1;
		if (p < 0)
			p = p + 2 * abs(cords->dx);
		else
		{
			if (cords->dx < 0)
				cords->cx -= 1;
			else
				cords->cx += 1;
			p = p + 2 * abs(cords->dx) - 2 * abs(cords->dy);
		}
		render_grad_line(cords, abs(cords->dy), i);
		img_pix_put(&data->img, cords->cx, cords->cy, cords->cc);
	}
}

void	check_slope(t_data *data, t_coords *cords)
{
	img_pix_put(&data->img, cords->ax, cords->ay, cords->ac);
	if (abs(cords->dx) > abs(cords->dy))
		slope_less_than_one(data, cords);
	else
		slope_greater_than_one(data, cords);
}
