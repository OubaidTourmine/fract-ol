/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:13:47 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/04 02:16:03 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mouse_handler_julia(int mousecode, int x, int y, t_data *data)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = scale(x, -2, 2, WIDTH) * data->cmplx.zoom + data->cmplx.shift_x;
	mouse_im = scale(y, 2, -2, HEIGHT) * data->cmplx.zoom + data->cmplx.shift_y;
	if (mousecode == 4)
	{
		data->cmplx.zoom *= 0.9;
	}
	if (mousecode == 5)
	{
		data->cmplx.zoom *= 1.1;
	}
	data->cmplx.shift_x = mouse_re - scale(x, -2, 2, WIDTH)
		* data->cmplx.zoom;
	data->cmplx.shift_y = mouse_im - scale(y, 2, -2, HEIGHT)
		* data->cmplx.zoom;
	julia_render(data);
	return (0);
}

int	key_handler_julia(int keycode, t_data *data)
{
	color_handler_julia(keycode, data);
	if (keycode == 65307)
	{
