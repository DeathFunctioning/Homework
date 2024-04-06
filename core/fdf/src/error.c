#include "fdf.h"

void	free_matrix(t_x_y_info **matrix, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_display(t_display *display)
{
	free_matrix(display->matrix);
	free(display);
}
