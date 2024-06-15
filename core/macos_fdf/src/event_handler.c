/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:51:07 by tbaker            #+#    #+#             */
/*   Updated: 2024/06/15 15:30:46 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *msg)
{
	ft_printf("%s\n", msg);
	exit (1);
}

void	close_free_win(t_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	free_matrix(data->matrix, data->y_axis_len);
	mlx_destroy_window(data->mlx, data->mlx_win);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		close_free_win(data);
		ft_printf("window closed\n");
		exit (0);
	}
	return (0);
}

int	close_handler(t_data *data)
{
	close_free_win(data);
	ft_printf("window closed\n");
	exit (0);
}

void	free_matrix(t_matrix **matrix, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
