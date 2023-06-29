/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:01:34 by aamaral-          #+#    #+#             */
/*   Updated: 2023/06/29 18:04:51 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_param(t_fractal *fractal, char *name)
{
	fractal->zoom = 1;
	fractal->colour = 0x00fff0ff;
	fractal->name = name;
	fractal->zoom_real = -0.75;
	fractal->zoom_imag = 0;
}

void	julia_param(t_fractal *fractal, char *name)
{
	fractal->zoom = 1;
	fractal->colour = 0x00ff0fff;
	fractal->name = name;
	fractal->c_real = 0;
	fractal->c_imag = 0;
	fractal->zoom_real = 0;
	fractal->zoom_imag = 0;
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while (s1[count] == s2[count] && count < n - 1 && s1[count] && s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
