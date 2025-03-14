/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outourmi <outourmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:02:42 by outourmi          #+#    #+#             */
/*   Updated: 2025/03/07 21:48:02 by outourmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 400
# define WIDTH 400

# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_color
{
	unsigned char	red;
	unsigned char	blue;
	unsigned char	green;
}					t_color;

typedef struct s_complx
{
	double			x_r;
	double			y_i;
	double			shift_y;
	double			shift_x;
	double			zoom;
}					t_complx;

typedef struct s_data
{
