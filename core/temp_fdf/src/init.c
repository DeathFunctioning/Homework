#include "fdf.h"

void	check_file_name(char *file)
{
	char	*cmp;
	int		i;
	int		start;

	start = ft_strlen(file) - 4;
	i = 0;
	cmp = ".fdf";
	while (file[start])
	{
		if (file[start] != cmp[i])
		{
			ft_printf("file name error");//remove <--------------------
			exit (1);
		}
		start++;
		i++;
	}
}

int	word_count(char *s)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i] == 32)
		i++;
	while (s[i])
	{
		if (s[i] == 32)
		{
			while (s[i] == 32)
				i++;
			if (s[i] == '\0' || s[i] == '\n')
				break ;
			wc++;
		}
		else
			i++;
	}
	if (wc < 1)
	{
		ft_printf("wc error");//remove test <-------------------------------------------------------
		exit (1);
	}
	return (wc + 1);
}

void	check_map_get_x_y(t_display *display, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd error");//remov <----------------------------------------------------------------
		exit (1);
	}
	line = get_next_line(fd);
	display->x_axis_len = word_count(line);
	while (line)
	{
		display->y_axis_len++;
		//free (&line);
		line = get_next_line(fd);
	}
	ft_printf("y_axis = %i\n", display->y_axis_len);//remov <----------------------------------------------------------------
	//free (&line);
	close(fd);
}

void	init(t_display	*display, char *file)
{
	check_file_name(file);
	display = malloc(sizeof(t_display));
	if (!display)
	{
		ft_printf("some malloc error need add real error handler");//remove<---------------------------------------
		exit (1);
	}
	check_map_get_x_y(display, file);
	init_matrix(display, file);
	print_matrix(display);
	display->mlx_connection = mlx_init();
	display->mlx_window = mlx_new_window(display->mlx_connection, WIDTH, HEIGHT, "fdf");
}
