/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:39:18 by lukarape          #+#    #+#             */
/*   Updated: 2021/07/27 14:39:21 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.height = 600;
	vars.width = 800;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "mlx");
	vars.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp, &vars.line_length, &vars.endian);
	vars.fractal = 3;
	if (argc != 2)
		vars.fractal = 3;
	if (check(argv[1]) == 0)
	{
		julian_init(&vars);
		vars.fractal = 0;
	}
	else if (check(argv[1]) == 1)
	{
		mandelbrot_init(&vars);
		vars.fractal = 1;
	}
	else if (check(argv[1]) == 2)
	{
		bship_init(&vars);
		vars.fractal = 2;
	}
	draw_win(&vars);
	mlx_hook(vars.win, 6, 1L < 6, mouse_julia, &vars);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, zoom, &vars);
	mlx_loop(vars.mlx);
}
