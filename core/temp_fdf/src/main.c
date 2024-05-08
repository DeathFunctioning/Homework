#include "fdf.h"

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
