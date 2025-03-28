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
		blue_val = (i * 10) % 255;
	}
	coloret = (red_val << 16 | green_val << 8 | blue_val);
	return (coloret);
}

void	handle_pixel_mandelbrot(int x, int y, t_data *data)
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
		z = sum(square(z), c);
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

void	mandelbrot_render(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			handle_pixel_mandelbrot(x, y, data);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
