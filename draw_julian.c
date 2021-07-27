/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julian.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:37:00 by lukarape          #+#    #+#             */
/*   Updated: 2021/07/27 14:37:02 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julian(t_vars *vars)
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
			m = julian(c, vars);
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

int		julian(comp c, t_vars *vars)
{
	int		n;
	comp	z;

	n = 0;
	z = (comp) {.real = vars->c_r, .imag = vars->c_i};
	while (module(c) <= 2 && n < vars->max_it)
	{
		c = multiply(c, c);
		c = add(c, z);
		n++;
	}
	return (n);
}

void	julian_init(t_vars *vars)
{
	vars->max_it = 50;
	vars->zoom = 200;
	vars->x1 = -2.0;
	vars->y1 = -1.9;
	vars->color = 265;
	vars->c_r = 0.285;
	vars->c_i = 0.01;
}
