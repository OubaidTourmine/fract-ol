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
	int				height;
	int				width;
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				itter;
	t_color			color;
	t_complx		cmplx;
	t_complx		julia_params;
}					t_data;

int					color_handler_cubic(int keycode, t_data *data);
int					mouse_handler_cubic(int mousecode, int x, int y,
						t_data *data);
int					key_handler_cubic(int keycode, t_data *data);
void				cubic_mandelbrot_render(t_data *data);
void				cubic_mandelbrot(void);
double				atoidbl(char *s);
int					mouse_handler(int mousecode, int x, int y, t_data *data);
int					key_handler(int keycode, t_data *data);
int					mouse_handler_julia(int mousecode, int x, int y,
						t_data *data);
int					key_handler_julia(int keycode, t_data *data);
int					ft_x(t_data *data);
void				handle_pixel_julia(int x, int y, t_data *data);
void				handle_pixel_mandelbrot(int x, int y, t_data *data);
t_complx			square(t_complx z);
t_complx			sum(t_complx z1, t_complx z2);
void				julia_render(t_data *data);
void				mandelbrot_render(t_data *data);
unsigned int		ft_color(t_color *color, int i);
double				scale(double unscaled_num, double new_min, double new_max,
						double old_max);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					color_handler(int keycode, t_data *data);
int					color_handler_julia(int keycode, t_data *data);
void				mandelbrot(void);
void				ft_putstr_fd(char *str);
int					ft_strcmp(char *s1, char *s2);

#endif