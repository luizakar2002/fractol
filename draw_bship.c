/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bship.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:36:45 by lukarape          #+#    #+#             */
/*   Updated: 2021/07/27 14:36:48 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_bship(t_vars *vars)
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
			m = bship(c, vars);
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

int		bship(comp c, t_vars *vars)
{
	int		n;
	comp	z;
    double  tmp;

	n = 0;
	z = (comp) {.real = 0, .imag = 0};
	while (module(z) <= 2 && n < vars->max_it)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = fabs(2 * z.real * z.imag) + c.imag;
		z.real = tmp;
		n++;
	}
	return (n);
}

void	bship_init(t_vars *vars)
{
	vars->max_it = 50;
	vars->zoom = 220;
	vars->x1 = -2.2;
	vars->y1 = -2.5;
	vars->color = 265;
}
