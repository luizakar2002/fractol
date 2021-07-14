#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	double	height;
	double	width;

	height = 1000;
	width = 1000;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "mlx");
	if (argc != 2)
		return (0);
	if (check(argv[1]) == 1)
		draw_mandelbrot(&vars, height, width);
	else if (check(argv[1]) == 0)
		draw_julian(&vars, height, width);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_mouse_hook(vars.win, zoom, &vars);
	mlx_loop(vars.mlx);
}
