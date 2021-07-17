#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	double	height;
	double	width;

	if (argc != 2)
		return (0);
	vars.height = 800;
	vars.width = 1100;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "mlx");
	vars.fractal = 9;
	if (check(argv[1]) == 1)
	{
		mandelbrot_init(&vars);
		vars.fractal = 1;
	}
	else if (check(argv[1]) == 0)
	{
		julian_init(&vars);
		vars.fractal = 0;
	}	
	draw_win(&vars);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, zoom, &vars);
	mlx_loop(vars.mlx);
}
