/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:28:00 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/02 03:53:51 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	key_handler_julia(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data);
		exit(1);
	}
	julia_render(data);
	return (0);
}

int	mouse_handler_julia(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		data->cmplx.zoom *= 0.95;
	if (mousecode == 5)
		data->cmplx.zoom *= 1.05;
	julia_render(data);
	return (0);
}
