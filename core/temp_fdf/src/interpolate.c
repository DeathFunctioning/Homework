#include "fdf.h"

void	render_grad_line(t_coords *cords, int steps, int c_steps)
{
	t_rgb	rgb;

	rgb.t = (float)c_steps / (float)steps;
	rgb.ra = (cords->ac >> 16) & 0xFF;
	rgb.ga = (cords->ac >> 8) & 0xFF;
	rgb.ba = cords->ac  & 0xFF;
	rgb.rb = (cords->bc >> 16) & 0xFF;
	rgb.gb = (cords->bc >> 8) & 0xFF;
	rgb.bb = cords->bc  & 0xFF;
	rgb.r = rgb.ra + (int)(rgb.rb - rgb.ra) * rgb.t;
	rgb.g = rgb.ga + (int)(rgb.gb - rgb.ga) * rgb.t;
	rgb.b = rgb.ba + (int)(rgb.bb - rgb.ba) * rgb.t;
	cords->cc = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
}
