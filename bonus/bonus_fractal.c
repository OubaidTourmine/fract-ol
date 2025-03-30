/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:57:44 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/07 21:46:50 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	cubic_mandelbrot(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->color.red = 255;
	data->color.green = 255;
	data->color.blue = 255;
	data->mlx = mlx_init();
	data->itter = 100;
	data->cmplx.zoom = 1.0;
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT,
			"cubic_mandelbrot");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->cmplx.shift_x = 0.0;
	data->cmplx.shift_y = 0.0;
	cubic_mandelbrot_render(data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_handler_cubic, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, ft_x, data);
	mlx_hook(data->mlx_win, 4, 1L << 2, mouse_handler_cubic, data);
	mlx_loop(data->mlx);
}

void	mandelbrot(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->color.red = 255;
	data->color.green = 255;
