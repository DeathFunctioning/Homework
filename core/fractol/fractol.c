# include "includes/fractol.h" 

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world");
	mlx_loop(mlx);
}

/*
int	main(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10) 
			|| ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{

	}
	else
	{

	}
}*/

