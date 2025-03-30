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
	data->color.blue = 255;
	data->mlx = mlx_init();
	data->itter = 100;
	data->cmplx.zoom = 1.0;
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "mandelbrot");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->cmplx.shift_x = 0.0;
	data->cmplx.shift_y = 0.0;
	mandelbrot_render(data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_handler, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, ft_x, data);
	mlx_hook(data->mlx_win, 4, 1L << 2, mouse_handler, data);
	mlx_loop(data->mlx);
}

void	julia(t_complx *parameters)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->color.red = 255;
	data->color.green = 255;
	data->color.blue = 255;
	data->mlx = mlx_init();
	data->itter = 100;
	data->cmplx.zoom = 1.0;
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "julia");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->cmplx.shift_x = 0.0;
	data->cmplx.shift_y = 0.0;
	data->julia_params = *parameters;
	free(parameters);
	julia_render(data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_handler_julia, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, ft_x, data);
	mlx_hook(data->mlx_win, 4, 1L << 2, mouse_handler_julia, data);
	mlx_loop(data->mlx);
}

int	handle_param(char *str)
{
	int	i;
	int	point;

	point = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
			point++;
		else if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	if (point > 1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_complx	*c;

	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		mandelbrot();
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if (handle_param(av[2]) == 0 || handle_param(av[3]) == 0)
		{
			ft_putstr_fd("./fractol julia 'Correct value' 'Correct value'\n");
			exit(0);
		}
		c = malloc(sizeof(t_complx));
		c->x_r = atoidbl(av[2]);
		c->y_i = atoidbl(av[3]);
		julia(c);
	}
	else if (ac == 2 && ft_strcmp(av[1], "cubic") == 0)
		cubic_mandelbrot();
	else
	{
		ft_putstr_fd("Please enter a valid arguments :\n./fractol_bonus ");
		ft_putstr_fd("mandlebrot\nor\n./fractol_bonus julia 'value1'");
		ft_putstr_fd(" 'value2'\nor\n./fract_ol_bonus cubic\n");
	}
}
