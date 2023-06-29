/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:23:16 by aamaral-          #+#    #+#             */
/*   Updated: 2023/06/29 19:23:25 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	freeall(fractal);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		close_window(fractal);
	else if (keycode == LEFT)
		fractal->zoom_real = fractal->zoom_real - CONST_DIST * fractal->zoom;
	else if (keycode == RIGHT)
		fractal->zoom_real = fractal->zoom_real + CONST_DIST * fractal->zoom;
	else if (keycode == DOWN)
		fractal->zoom_imag = fractal->zoom_imag + CONST_DIST * fractal->zoom;
	else if (keycode == UP)
		fractal->zoom_imag = fractal->zoom_imag - CONST_DIST * fractal->zoom;
	else if (keycode == PLUS)
		fractal->colour += CONST_COLOUR;
	else if (keycode == MINUS)
		fractal->colour -= CONST_COLOUR;
	else if (keycode == Z)
		fractal->zoom = 1;
	if (keycode != ESC)
		fractalsetup(fractal);
	return (0);
}

int	mouse_hook(int key_code, int x, int y, t_fractal *fractal)
{
	if (key_code == 1 && !ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->c_real = ((double) x / WIDTH * CARTESIAN_DIST - \
			(CARTESIAN_DIST / 2));
		fractal->c_imag = ((double) y / (WIDTH / RATIO) * \
			(CARTESIAN_DIST / RATIO) - (CARTESIAN_DIST / (RATIO * 2)));
		fractal->zoom = 1; 
	}
	else if (key_code == 5)
		fractal->zoom *= CONST_ZOOM;
	else if (key_code == 4)
		fractal->zoom /= CONST_ZOOM;
	fractalsetup(fractal);
	return (0);
}
