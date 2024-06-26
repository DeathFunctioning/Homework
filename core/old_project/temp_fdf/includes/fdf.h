/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:04:39 by tbaker            #+#    #+#             */
/*   Updated: 2024/05/19 19:05:55 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define STARSHIP_COLOUR 0xEAE243
# define WHITE_COLOUR 0xFFFFFF
# define BUDDA_GOLD_COLOUR 0xA9A10A
# define TURBO_COLOUR 0xF5F300
# define BITTER_COLOUR 0x8E8E80
# define TABASCO_COLOUR 0xA02712
# define CERULEAN_COLOUR 0x2D46D7
# define GREEN_COLOUR 0x33FF00
# define BLACK_COLOUR 0x000000

typedef struct s_rgb
{
	int			ra;
	int			rb;
	int			ga;
	int			gb;
	int			ba;
	int			bb;
	int			r;
	int			b;
	int			g;
	float		t;
}	t_rgb;

typedef struct s_coords
{
	int			ax;
	int			ay;
	int			cx;
	int			cy;
	int			bx;
	int			by;
	int			dy;
	int			dx;
	int			ac;
	int			bc;
	int			cc;

}	t_coords;

typedef struct s_matrix
{
	int			x;
	int			y;
	int			z;
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
	int			x_margin;
	int			y_margin;
	int			box_len;
	t_img		img;
	t_matrix	**matrix;

}	t_data;

//init.c

void	check_file_name(char *file);
int		word_count(char *s, int i);
void	check_map_get_x_y(t_data *data, char *file);
void	init(t_data *data, char *file);

//matrix.c

void	free_array(char **s);
int		ft_atoi_hex(char *hex);
void	assign_alt_colour(t_matrix *matrix, char **split_line, int len, int i);
void	init_matrix_data(t_matrix *matrix, int fd, int len);
void	init_matrix(t_data *data, char *file);

//draw.c

void	img_pix_put(t_img *img, int x, int y, int colour);
void	isometric(t_data *data, int y, int i);

//render_line.c

void	slope_less_than_one(t_data *data, t_coords *cords);
void	slope_greater_than_one(t_data *data, t_coords *cords);
void	check_slope(t_data *data, t_coords *cords);

//render.c

int		render(t_data *data);
void	render_map(t_data *data);
void	render_background(t_data *data, int colour);
void	render_x_line(t_data *data, int x, int y);
void	render_y_line(t_data *data, int x, int y);

//event_handler.c

void	close_free_win(t_data *data);
int		key_handler(int keycode, t_data *data);
int		close_handler(t_data *data);
void	free_matrix(t_matrix **matrix, int len);
void	error(char *msg);

//plot_points.c

void	plot_points(t_data *data);
int		get_cell_size(t_data *data);

//interpolate.c

void	render_grad_line(t_coords *cords, int steps, int c_steps);

#endif
