/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:28:58 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/07 21:38:18 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	atoidbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	handle_pixel_julia(int x, int y, t_data *data)
{
	t_complx	z;
	int			i;
	int			color;

	i = 0;
	z.x_r = (scale(x, -2, 2, WIDTH) * data->cmplx.zoom) + data->cmplx.shift_x;
	z.y_i = (scale(y, 2, -2, HEIGHT) * data->cmplx.zoom) + data->cmplx.shift_y;
	color = ft_color(&data->color, i);
	while (i < data->itter)
	{
		z = sum(square(z), data->julia_params);
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

void	julia_render(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			handle_pixel_julia(x, y, data);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
