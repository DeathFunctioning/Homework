/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_grad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:58:18 by tbaker            #+#    #+#             */
/*   Updated: 2024/05/19 19:00:08 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colour_grad(t_data *data, t_coords *cords)
{
	if (cords->ac == cords->bc)
		cords->cc = cords->ac;
	else
}

float	fraction(t_coords *cords)
{
	float	fraction;

	if (abs(cordsdx) > abs(dy))
		fraction = cal_fraction((float)cords->ax, (float)cords->bx, (float)cords->cx);
	else
		fraction = cal_fraction((float)cords->ay, (float)cords->by, (float)cords->cy);
	return (fraction);
}

float	cal_fraction(float p1, float p2, float p)
{
	if (p1 != p2)
		return ((p - p1) / (p2 - p1));
	else
		return (0);
}


img_pix_put(&data->img, cords->cx, cords->cy, cords->cc);
