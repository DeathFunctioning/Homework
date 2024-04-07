#include "fdf.h"

//will need to add free aftre distorying window

//need to update key code for mac
int	key_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free (data->mlx);
		ft_printf("add code to close x axis lan = %i\n", data->x_axis_len);
		exit (0);
	}
	else
		ft_printf("keycode = %i\n", keycode);
	return (0);
}
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Only two arguments = ./fdf file.fdf\n");
		return (1);
	}
	init(&data, argv[1]);
	print_matrix(&data);//<--------------remove <<---------
	mlx_hook(data.mlx_win, 2, 1L<<0, key_handler, &data);
	mlx_loop(data.mlx);
	return (0);
}
/*
int	main(void)
{
	int		y;
	int		x;
	void	*mlx_connection;
	void	*mlx_window;

	y = HEIGHT * 0.1;
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "My first window");
	while (y < HEIGHT * 0.9)
	{
		x = WIDTH * 0.1;
		while (x < WIDTH * 0.9)
		{
			mlx_pixel_put(mlx_connection, mlx_window, x, y, rand() % 0x1000000);
			x++;
		}
		y++;
	}
	mlx_loop(mlx_connection);
	return (0);
}*/
