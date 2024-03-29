# include "fdf.h"

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
}
