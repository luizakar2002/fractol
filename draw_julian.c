#include "fractol.h"

void	draw_julian(t_vars *vars)
{
	double	i;
	double	j;
	comp	c;
	int		color;
	int		m;

	i = 0;
	vars->zoom = 300;
	vars->color = 2056;
	while (i < vars->width)
	{
		j = 0;
		while (j < vars->height)
		{
			c.real = i / vars->zoom + vars->x1;
			c.imag = j / vars->zoom + vars->y1;
			m = julian(c, vars);
			mlx_pixel_put((*vars).mlx, (*vars).win, i, j, m * vars->color);
			j++;
		}
		i++;
	}

}

void	julian_init(t_vars *vars)
{
	vars->max_it = 50;
	vars->zoom = 200;
	vars->x1 = -2.0;
	vars->y1 = -1.9;
	vars->color = 265;
	//vars->c_r = 0.285;
	//vars->c_i = 0.01;
	//vars->julia_mouse = 1;
}