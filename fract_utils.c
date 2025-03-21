/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:06:15 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/07 22:55:21 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_x(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(1);
	return (0);
}

double	scale(double unscaled_num, double new_min, double new_max,
		double old_max)
{
	return (((new_max - new_min) * (unscaled_num - 0) / (old_max - 0)
			+ new_min));
}
