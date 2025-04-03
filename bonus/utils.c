/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:41:45 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/08 00:00:02 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mouse_handler(int mousecode, int x, int y, t_data *data)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = scale(x, -2, 2, WIDTH) * data->cmplx.zoom
		+ data->cmplx.shift_x;
	mouse_im = scale(y, 2, -2, HEIGHT) * data->cmplx.zoom
		+ data->cmplx.shift_y;
	if (mousecode == 4)
	{
		data->cmplx.zoom *= 0.9;
	}
	if (mousecode == 5)
	{
		data->cmplx.zoom *= 1.1;
	}
	data->cmplx.shift_x = mouse_re - scale(x, -2, 2, WIDTH) * data->cmplx.zoom;
	data->cmplx.shift_y = mouse_im - scale(y, 2, -2, HEIGHT) * data->cmplx.zoom;
	mandelbrot_render(data);
	return (0);
}

int	key_handler(int keycode, t_data *data)
{
	color_handler(keycode, data);
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data);
		exit(1);
	}
	else if (keycode == 65363)
		data->cmplx.shift_x += 0.1 * data->cmplx.zoom;
	else if (keycode == 65361)
		data->cmplx.shift_x -= 0.1 * data->cmplx.zoom;
	else if (keycode == 65362)
		data->cmplx.shift_y += 0.1 * data->cmplx.zoom;
	else if (keycode == 65364)
		data->cmplx.shift_y -= 0.1 * data->cmplx.zoom;
	mandelbrot_render(data);
	return (0);
}

int	color_handler(int keycode, t_data *data)
{
	if (keycode == 114)
	{
		data->color.red = 255;
		data->color.green = 0;
		data->color.blue = 0;
	}
	else if (keycode == 103)
	{
		data->color.red = 0;
		data->color.green = 255;
		data->color.blue = 0;
	}
	else if (keycode == 98)
	{
		data->color.red = 0;
		data->color.green = 0;
		data->color.blue = 255;
	}
	mandelbrot_render(data);
	return (0);
}

int	color_handler_cubic(int keycode, t_data *data)
{
	if (keycode == 114)
	{
		data->color.red = 255;
		data->color.green = 0;
		data->color.blue = 0;
	}
	else if (keycode == 103)
	{
		data->color.red = 0;
		data->color.green = 255;
		data->color.blue = 0;
	}
	else if (keycode == 98)
	{
		data->color.red = 0;
		data->color.green = 0;
		data->color.blue = 255;
	}
	cubic_mandelbrot_render(data);
	return (0);
}
