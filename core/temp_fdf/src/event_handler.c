#include "fdf.h"

void	close_free_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_display(data->mlx);
	free_matrix(data->matrix, data->y_axis_len);
	free (data->mlx);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		close_free_win(data);
		ft_printf("closed window");
		exit (0);
	}
	else
		ft_printf("keycode = %i\n", keycode);
	return (0);
}

void	free_matrix(t_matrix **matrix, int len)
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

