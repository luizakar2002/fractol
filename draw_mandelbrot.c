#include "fractol.h"

void	draw_mandelbrot(t_vars *vars)
{
	double	i;
	double	j;
	comp	c;
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
		//	printf("%d\n", m);
		//	if (m == vars->max_it)
		//		vars->color = 0;
		//	else
		//		vars->color *= m;
			mlx_pixel_put((*vars).mlx, (*vars).win, i, j, m * vars->color);
			j++;
		}
		i++;
	}
}

void	clean_win(t_vars *vars)
{
	int	i;
	int j;

	i = 0;
	while (i < vars->width)
	{
		j = 0;
		while (j < vars->height)
		{
			mlx_pixel_put((*vars).mlx, (*vars).win, i, j, 0);
			j++;
		}
		i++;
	}
}

void	draw_win(t_vars *vars)
{
	if (vars->fractal == 1)
	{
		draw_mandelbrot(vars);
	}
	else if (vars->fractal == 0)
	{
		draw_julian(vars);
	}
}

void	mandelbrot_init(t_vars *vars)
{
	vars->max_it = 50;
	vars->zoom = 300;
	vars->x1 = -2.05;
	vars->y1 = -1.3;
	vars->color = 265;
}
