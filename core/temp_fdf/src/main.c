#include "fdf.h"

/*
int	key_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_image(data->mlx, data->img.mlx_img);
		mlx_destroy_display(data->mlx);
		free (data->mlx);
		ft_printf("add code to close x axis lan = %i\n", data->x_axis_len);
		exit (0);
	}
	else
		ft_printf("keycode = %i\n", keycode);
	return (0);
}*/
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		init(&data, argv[1]);
		mlx_loop_hook(data.mlx, &render, &data);
		mlx_hook(data.mlx_win, 2, 1L<<0, key_handler, &data);
		mlx_loop(data.mlx);
		return (0);
	}
	ft_printf("Only two arguments = ./fdf file.fdf\n");
	return (1);
}
