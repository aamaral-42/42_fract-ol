# 42_fract-ol

In this project we are suppose to generate some fractals: Mandelbrot and Julia.

I just loved this project and it will be in a working in progress status for a long time. I have so many improvements in mind to better the result that time will be the problem.

1. [Key points](#key-points)
1. [Prepare the binaries](#prepare-the-binaries)
2. [The functioning of keybord keys](#the-functioning-of-keybord-keys)
3. [The functioning of mouse keys](#the-functioning-of-mouse-keys)
4. [Macros to user experiment](#macros-to-user-experiment)

## Key points

- Use of RATIO between WIDTH and heigth instead of using the variable Heigth (see section below for explanations)
- Use of Linear Transformation to pass coordinates from the complex plane to the mlx window (see section below for explanations)
- Use of ratio to get how much the value of colour changes by changing a unit of ITERATIONS( 16^6 / ITERATIONS)

##  Prepare the binaries
- 1. copy the mlx library (in the project subject page) to the folder were C files are, unzip it and run ```make``` inside the **mlx folder**
- 2. in CLI run ```make``` in the folder were C files from fractol are
- 3. in CLI run ```./fractol mandelbrot``` or ```./fractol julia```

## **The functioning of keybord keys**:
- **keys + and -**     to change colours
- **arrow keys**       to move fractal around the window
- **z key**             to restore zoom at 1
- **ESC key**           to close fractal window

## **The functioning of mouse keys**:
 - **left click** to select a point in the julia window
 - **mouse scroll** to zoom in and zoom out 

## **Macros to user experiment**
I used the following MACROS (in fractol.h) but you can play around with them

- define **WIDTH 1280** ---------------- defines the width of the mlx window (maximum should be 1920)
- define **RATIO (1.3333333)**- -------- defines the width to heigth ratio of the mlx window, this value represent a 4:3 ratio (closer to 1 will be a square)
- define **ITERATIONS 250** ------------ defines the maximum number of iterations to consider that point belongs to Mandelbrot or Julia set (more is better for better definition at borders of the sets but more computations are made)
- define **CARTESIAN_DIST 8** ---------- defines the range/total_distance of the complex plane that will be passed to the mlx window (the higher the smaller the Mandelbrot and Julia sets will be, a bigger area of complex plane is represented in the window)
- define **CONST_ZOOM 1.42** ----------- defines what level of zoom will be applied at each mouse scroll (higher zoom the change will be very fast)
- define **CONST_DIST 0.24** ----------- defines what is the distance of complex plane that each time an arrow key is released will shift 
- define **CONST_COLOUR 242** ---------- defines how many colours will be skipped at any time the keys are released
- define **MAXCOLOURS 0x00ffffff** ----- defines the maximum range of colours in a RGB colour scheme (you shouldn't change these)




Both Mandelbrot and Julia sets have the same underline funtion ```f(z) = z^2 + c``` (so both fractals are related) that is iterated untill infinity (or you need to define a maximum number of ITERATIONS to be computable):

f(z) = z^2 + c

It is extraordinary that this simple funtion can generate such beautiful images.

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


