#include "fdf.h"

void	close_free_win(t_data *data)
{
	mlx_destory_window(data->mlx, data->mlx_win);
	mlx_destory_display(data->mlx);
	free (data->mlx);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		close_free_win(data);
		exit (0);
	}
	else
		ft_printf("keycode = %i\n", keycode);
	return (0);
}


