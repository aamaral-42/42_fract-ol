/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:03:16 by aamaral-          #+#    #+#             */
/*   Updated: 2023/06/29 22:12:47 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1280
# define RATIO (1.77778)
# define ITERATIONS 250
# define MAXCOLOURS 0x00ffffff
# define CARTESIAN_DIST 8
# define CONST_ZOOM 1.42
# define CONST_DIST 0.24
# define CONST_COLOUR 42
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define Z 122
# define PLUS 65451
# define MINUS 65453

typedef struct s_fractal {
	char	*name;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	double	zoom;
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
	int		colour;
	double	carte_distance;
	double	zoom_real;
	double	zoom_imag;
}			t_fractal;

void	mandelbrot_param(t_fractal *fractal, char *name);
void	julia_param(t_fractal *fractal, char *name);
void	mandelbrotset(t_fractal *mandel);
void	juliaset(t_fractal *julia);
int		set_colour_mandelbrot(double c_real, double c_imag);
int		c_julia(double c_re, double c_img, double z_re, double z_img);

void	fractalsetup(t_fractal *fractal);
void	show_options(void);
int		my_mlx_pixel_put(t_fractal *fractal, int x, int y, int colour);
int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int key_code, int x, int y, t_fractal *fractal);
int		close_window(t_fractal *fractal);

int		freeall(t_fractal *fractal);

size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
