#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_complex
{
	double	real;
	double	imag;
}				comp;

typedef struct 	s_vars {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		fractal;
	double	zoom;
	int		max_it;
	int		it;
	int		color;
	double	x1;
	double	y1;
}				t_vars;

comp	add(comp a, comp b);
comp	multiply(comp a, comp b);
double	module(comp a);
int		mandelbrot(comp c, t_vars *vars);
int		julian(comp c, t_vars *vars);
void	draw_mandelbrot(t_vars *vars);
void	draw_julian(t_vars *vars);
int		check(char *str);
int		close(int keycode, t_vars *vars);
int		zoom(int button, int x, int y, t_vars *vars);
void	clean_win(t_vars *vars);
void	draw_win(t_vars *vars);
void	mandelbrot_init(t_vars *vars);
void	julian_init(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
