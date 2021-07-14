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
}				t_vars;

comp	add(comp a, comp b);
comp	multiply(comp a, comp b);
double	module(comp a);
int		mandelbrot(comp c);
int		julian(comp c);
void	draw_mandelbrot(t_vars *vars, double height, double width);
void	draw_julian(t_vars *vars, double height, double width);
int		check(char *str);
int		trgb(int t, int r, int g, int b);
int		create_color(int m);
int		close(int keycode, t_vars *vars);
int		zoom(int button, int x, int y, t_vars *vars);
