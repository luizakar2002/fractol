#include "fractol.h"

void	draw_mandelbrot(t_vars *vars)
{
	int		i;
	int		j;
	comp	c;
	int		color;
	int		m;

	i = 0;
	while (i < vars->width)
	{
		j = 0;
		while (j < vars->height)
		{
			c.real = i / vars->zoom + vars->x1;
			c.imag = j / vars->zoom + vars->y1;
			m = mandelbrot(c, vars);
			if (m == vars->max_it)
				color = 0;
			else if (m < vars->max_it)
				color = m * vars->color;
			my_mlx_pixel_put(vars, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

int		mandelbrot(comp c, t_vars *vars)
{
	int		n;
	comp	z;

	n = 0;
	z = (comp) {.real = 0, .imag = 0};
	while (module(z) <= 2 && n < vars->max_it)
	{
		z = multiply(z, z);
		z = add(z, c);
		n++;
	}
	return (n);
}

void	draw_win(t_vars *vars)
{
	if (vars->fractal == 0)
		draw_julian(vars);
	else if (vars->fractal == 1)
		draw_mandelbrot(vars);
	else if (vars->fractal == 2)
		draw_bship(vars);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 255, " H - help");	
	if (vars->fractal == 3)
	{
		show_inst(vars);
		mlx_string_put(vars->mlx, vars->win, 0, 0, 0, " H - help");
	}
}

void	clean_win(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (i < vars->width)
	{
		j = 0;
		while (j < vars->height)
		{
			my_mlx_pixel_put(vars, i, j, 0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void	mandelbrot_init(t_vars *vars)
{
	vars->max_it = 50;
	vars->zoom = 200;
	vars->x1 = -2.05;
	vars->y1 = -1.3;
	vars->color = 265;
}
