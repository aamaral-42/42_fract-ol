/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:25:57 by aamaral-          #+#    #+#             */
/*   Updated: 2023/06/29 18:49:00 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, (WIDTH / RATIO));
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, \
		&fractal->line_length, &fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

int	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int colour)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x * \
		(fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
	return (0);
}

void	show_options(void)
{
	write(1, "\nPlease enter the fractal that you want: ", 42);
	write(1, "mandelbrot or julia\n\n", 21);
	exit(1);
}

int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]) == 10)
			mandelbrot_param(&fractal, argv[1]);
		else if (!ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]) == 5)
			julia_param(&fractal, argv[1]);
		else
			show_options();
		fractal.mlx = mlx_init();
		fractal.win = mlx_new_window(fractal.mlx, WIDTH, \
			(WIDTH / RATIO), fractal.name);
		fractal.img = mlx_new_image(fractal.mlx, WIDTH, (WIDTH / RATIO));
		fractalsetup(&fractal);
		mlx_key_hook(fractal.win, key_hook, &fractal);
		mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		mlx_hook(fractal.win, 17, 0, close_window, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
		show_options();
	return (0);
}
