#include "fractol.h"

int	main()
{
	int		i;
	int		j;
	int		height;
	int		width;
	void	*mlx_ptr;
	void	*win_ptr;

	height = 500;
	width = 800;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "mlx");
	//mlx_pixel_put(mlx_ptr, win_ptr, 50, 50, 0x00FFFFFF);
	//mlx_string_put(mlx_ptr, win_ptr, 0, 0, 0x00FFFFFF, "dsad");
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			if (mandelbrot(CMPLX(i, j)) >= 80)
			{
				printf("%d\n", mandelbrot((CMPLX(i, j))));
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00FFFFFF);
			}
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
}
