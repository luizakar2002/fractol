#include "fractol.h"

void	draw_mandelbrot(t_vars *vars, double height, double width)
{
	double	i;
	double	j;
	comp	c;
	int		color;
	int		m;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			c.real = -2 + ((4 * i) / width);
			c.imag = 2 - ((4 * j) / height);
			m = mandelbrot(c);
			color = create_color(m);
			mlx_pixel_put((*vars).mlx, (*vars).win, i, j, color);
			j++;
		}
		i++;
	}
}
