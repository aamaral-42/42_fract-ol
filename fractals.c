/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:41:04 by aamaral-          #+#    #+#             */
/*   Updated: 2023/06/29 16:41:19 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	c_julia(double c_real, double c_imag, double z_real, double z_imag)
{
	int		k;
	double	temp_complex;

	k = -1;
	temp_complex = 0;
	while (++k < ITERATIONS)
	{
		temp_complex = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2 * z_real * z_imag + c_imag;
		z_real = temp_complex;
		if (z_real * z_real + z_imag * z_imag > 4)
			return (k);
	}
	return (0);
}

void	juliaset(t_fractal *julia)
{
	int		i_window;
	int		j_window;
	int		iterations;
	double	z_real;
	double	z_imag;

	j_window = -1;
	while (++j_window < (WIDTH / RATIO))
	{
		i_window = -1;
		iterations = 0;
		while (++i_window < WIDTH)
		{
			z_real = julia->zoom * (i_window - WIDTH / 2) * CARTESIAN_DIST / \
				(2 * WIDTH) + julia->zoom_real;
			z_imag = julia->zoom * (-j_window + WIDTH / (2 * RATIO)) / \
				(2 * WIDTH) * CARTESIAN_DIST - julia->zoom_imag;
			iterations = c_julia(julia->c_real, julia->c_imag, z_real, z_imag);
			if (iterations == 0)
				my_mlx_pixel_put(julia, i_window, j_window, 0);
			else
				my_mlx_pixel_put(julia, i_window, j_window, \
					iterations * julia->colour * (MAXCOLOURS / ITERATIONS));
		}
	}
}

int	set_colour_mandelbrot(double c_real, double c_imag)
{
	int		k;
	double	t_real;
	double	t_imag;
	double	temp_complex;

	k = -1;
	temp_complex = 0;
	t_real = c_real;
	t_imag = c_imag;
	while (++k < ITERATIONS)
	{
		temp_complex = t_real * t_real - t_imag * t_imag + c_real;
		t_imag = 2 * t_real * t_imag + c_imag;
		t_real = temp_complex;
		if (t_real * t_real + t_imag * t_imag > 4)
			return (k);
	}
	return (0);
}

void	mandelbrotset(t_fractal *mandel)
{
	int		i_window;
	int		j_window;
	int		iterations;
	double	c_real;
	double	c_imag;

	j_window = -1;
	while (++j_window < (WIDTH / RATIO))
	{
		i_window = -1;
		iterations = 0;
		while (++i_window < WIDTH)
		{
			c_real = mandel->zoom * (i_window - WIDTH / 2) * CARTESIAN_DIST / \
				(2 * WIDTH) + mandel->zoom_real;
			c_imag = mandel->zoom * (-j_window + WIDTH / (2 * RATIO)) / \
				(2 * WIDTH) * CARTESIAN_DIST - mandel->zoom_imag;
			iterations = set_colour_mandelbrot(c_real, c_imag);
			if (iterations == 0)
				my_mlx_pixel_put(mandel, i_window, j_window, 0x00000000);
			else
				my_mlx_pixel_put(mandel, i_window, j_window, \
					iterations * mandel->colour * (MAXCOLOURS / ITERATIONS));
		}
	}
}
