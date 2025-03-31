/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:13:55 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/07 21:38:39 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

t_complx	cube(t_complx z)
{
	t_complx	result;

	result.x_r = (z.x_r * z.x_r * z.x_r) - (3 * z.x_r * z.y_i * z.y_i);
	result.y_i = (3 * z.x_r * z.x_r * z.y_i) - (z.y_i * z.y_i * z.y_i);
	return (result);
}

void	handle_pixel_cubic_mandelbrot(int x, int y, t_data *data)
{
	t_complx	z;
	t_complx	c;
	int			i;
	int			color;

	i = 0;
	z.x_r = 0.0;
	z.y_i = 0.0;
	c.shift_x = 0.0;
	c.shift_y = 0.0;
	c.x_r = (scale(x, -2, 2, WIDTH) * data->cmplx.zoom) + data->cmplx.shift_x;
	c.y_i = (scale(y, 2, -2, HEIGHT) * data->cmplx.zoom) + data->cmplx.shift_y;
	while (i < data->itter)
	{
		z = sum(cube(z), c);
		if ((z.x_r * z.x_r) + (z.y_i * z.y_i) > 4)
		{
			color = ft_color(&data->color, i);
			my_mlx_pixel_put(data, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(data, x, y, WHITE);
}

void	cubic_mandelbrot_render(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
