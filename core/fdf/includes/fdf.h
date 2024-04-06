#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

# define WIDTH 500	
# define HEIGHT	500

typedef struct s_x_y_info
{
	int			altitude;
	int			colour;
}	t_x_y_info;

typedef struct s_data
{
	void		*mlx_connection;
	void		*mlx_window;
	int			x_axis_len;
	int			y_axis_len;
	t_x_y_info	**matrix;

}	t_data;

//init.c

void	check_file_name(char *file);
int		word_count(char *s);
void	check_map_get_x_y(t_data *data, char *file);
void	init(t_data *data, char *file);

//matrix.c

int		ft_atoi_hex(char *hex);
void	assign_alt_colour(t_x_y_info *matrix, char **split_line, int len, int i);
void	init_matrix_data(t_x_y_info *matrix, int fd, int len);
void	init_matrix(t_data *data, char *file);

//test_remove.c

void	print_matrix(t_data *data);

#endif
