# include "fdf.h"

void	print_matrix(t_display *display)
{
	int			x;
	int			y;
	int			x_axis;
	int			y_axis;

	y = 0;
	x_axis = display->x_axis_len;
	y_axis = display->y_axis_len;
	ft_printf("printing matrix\n");
	while (y < y_axis)
	{
		x = 0;
		while (x < x_axis)
		{
			ft_printf("%i ", display->matrix[y][x].altitude);
			ft_printf("%i ", display->matrix[y][x].colour);
			x++;
		}
		ft_printf("\n");
		y++;
	}

}
