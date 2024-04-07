#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

# define WIDTH 1920	
# define HEIGHT	1080

typedef struct s_matrix
{
	int			altitude;
	int			colour;
}	t_matrix;

typedef struct s_img
{
	void		*mlx_img;
	char		*mlx_addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			x_axis_len;
	int			y_axis_len;
	t_img		img;
	t_matrix	**matrix;

}	t_data;

//init.c

void	check_file_name(char *file);
int		word_count(char *s);
void	check_map_get_x_y(t_data *data, char *file);
void	init(t_data *data, char *file);

//matrix.c

int		ft_atoi_hex(char *hex);
void	assign_alt_colour(t_matrix *matrix, char **split_line, int len, int i);
void	init_matrix_data(t_matrix *matrix, int fd, int len);
void	init_matrix(t_data *data, char *file);

//test_remove.c

void	print_matrix(t_data *data);

#endif
