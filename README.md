# 42_fract-ol
In this project we are suppose to generate some fractals: Mandelbrot and Julia.


1st step copy the mlx library to the folder were C files are, unzip it and run >make inside the mlx folder

2nd step in CLI run >make in the folder were C files from fractol are

3rd step in CLI run >./fractol mandelbrot or ./fractol julia

The functioning keybord keys:
- keys + and -     for change colours
- arrow keys       to move fractal around
- z                to restore zoom as 1
- ESC             to close fractal window

The functioning mouse keys:
 - left click to select a point in the julia window
 - mouse scroll to zoom in and zoom out 

Both Mandelbrot and Julia sets have the same funtion (so they are related) that is iterated untill infinity (or define a maximum number of ITERATIONS to be computable):


f(z) = z^2 + c

if in any of the iterations the value of f(z) ends up out the circle of radius 2 we consider that doesn't belong to Mandelbrot and Julia set. (in Julia set the actual radious should be R=(1+sqr(1+4|c|)/2)

In Mandelbrot set, the value of z is zero and for each value of c we are going to substitute iteratively the result and perform the operations in the function f(z)

In Julia set, the c value is constant and defined from begining and the z value is the point of interest. This will give different (filled) julia sets
 for each value of z chosen from the left click of the mouse.

To choose the mlx window dimensions, I used the WIDTH and RATIO variables (HEIGHT = WIDTH / RATIO). In this way it's easier to maintain the proportions to pass from the complex plane into mlx window. 

passing from the complex plane to the mlx window coordinates

c_real = mandel->zoom * (i_window - WIDTH / 2) * CARTESIAN_DIST / (2 * WIDTH) + mandel->zoom_real;

c_imag = mandel->zoom * (-j_window + WIDTH / (2 * RATIO)) / (2 * WIDTH) * CARTESIAN_DIST - mandel->zoom_imag;


z_real = julia->zoom * (i_window - WIDTH / 2) * CARTESIAN_DIST / (2 * WIDTH) + julia->zoom_real;

z_imag = julia->zoom * (-j_window + WIDTH / (2 * RATIO)) / (2 * WIDTH) * CARTESIAN_DIST - julia->zoom_imag;

I used the following MACROS (in fractol.h) but you can play around with them

- define WIDTH 1280              -  defines the width of the mlx window
- define RATIO (1.3333333)       -  defines the width to heigth ratio of the mlx window (closer to 1 will be a square)
- define ITERATIONS 250          -  defines the maximum number of iterations to consider that the point belongs to Mandelbrot or Julia set (more is better for better definition at borders of the sets)
- define MAXCOLOURS 0x00ffffff   -  defines the maximum range of colours in a RGB colour scheme
- define CARTESIAN_DIST 8        -  defines the range/total_distance of the complex plane that will be passed to the mlx window (the higher the smaller the Mandelbrot and Julia sets will be)
- define CONST_ZOOM 1.42         -  defines what level of zoom will be applied at each mouse scroll (higher zoom will be very fast)
- define CONST_DIST 0.24         - defines what is the distance of complex plane that each time arrow key is released will shift 
- define CONST_COLOUR 242        - defines how many colours will be skipped
