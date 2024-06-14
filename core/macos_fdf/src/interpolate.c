/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:46:06 by tbaker            #+#    #+#             */
/*   Updated: 2024/06/14 19:19:08 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//rgb.g = rgb.ga + (int)(rgb.gb - rgb.ga) * rgb.t;
//changed for norminete change back if color dont work
void	render_grad_line(t_coords *cords, int steps, int c_steps)
{
	t_rgb	rgb;

	rgb.t = (float)c_steps / (float)steps;
	rgb.ra = (cords->ac >> 16) & 0xFF;
	rgb.ga = (cords->ac >> 8) & 0xFF;
	rgb.ba = cords->ac & 0xFF;
	rgb.rb = (cords->bc >> 16) & 0xFF;
	rgb.gb = (cords->bc >> 8) & 0xFF;
	rgb.bb = cords->bc & 0xFF;
	rgb.r = rgb.ra + rgb.t * (int)(rgb.rb - rgb.ra);
	rgb.g = rgb.ga + rgb.t * (int)(rgb.gb - rgb.ga);
	rgb.b = rgb.ba + rgb.t * (int)(rgb.bb - rgb.ba);
	cords->cc = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
}
