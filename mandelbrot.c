/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:39:39 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/07 22:53:43 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_complx	sum(t_complx z1, t_complx z2)
{
	t_complx	result;

	result.x_r = z1.x_r + z2.x_r;
	result.y_i = z1.y_i + z2.y_i;
	return (result);
}

t_complx	square(t_complx z)
{
	t_complx	result;

	result.x_r = (z.x_r * z.x_r) - (z.y_i * z.y_i);
	result.y_i = 2 * z.x_r * z.y_i;
	return (result);
}

unsigned int	ft_color(t_color *color, int i)
{
	unsigned int	coloret;
	int				red_val;
	int				green_val;
	int				blue_val;

	red_val = 0;
	green_val = 0;
	blue_val = 0;
	if (color->red > 0)
		red_val = (i * 30) % 255;
	if (color->green > 0)
		green_val = (i * 30) % 255;
	if (color->blue > 0)
		blue_val = (i * 20) % 255;
	if (red_val == 0 && green_val == 0 && blue_val == 0)
	{
		red_val = (i * 10) % 255;
		green_val = (i * 10) % 255;
