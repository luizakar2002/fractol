#include "fractol.h"

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

void	zoom_in(int x, int y, t_vars *vars)
{
	vars->x1 = (x / vars->zoom + vars->x1) - (x / (vars->zoom * 1.3));
	vars->y1 = (y / vars->zoom + vars->y1) - (y / (vars->zoom * 1.3));
	vars->zoom *= 1.3;
	vars->max_it++;
}

void	zoom_out(int x, int y, t_vars *vars)
{
	vars->x1 = (x / vars->zoom + vars->x1)  - (x / (vars->zoom / 1.3));
	vars->y1 = (y / vars->zoom + vars->y1) - (y / (vars->zoom / 1.3));
	vars->zoom /= 1.3;
	vars->max_it--;
}

int	zoom(int button, int x, int y, t_vars *vars)
{
	if (button == 5)
		zoom_in(x, y, vars);
	else if (button == 4)
		zoom_out(x, y, vars);
	clean_win(vars);
	draw_win(vars);
	return (0);
}

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		vars->max_it += 50;
	else if (keycode == 78)
		vars->max_it -= 50;
	else if (keycode == 123)
		vars->x1 -= 30 / vars->zoom;
	else if (keycode == 124)
		vars->x1 += 30 / vars->zoom;
	else if (keycode == 125)
		vars->y1 += 30 / vars->zoom;
	else if (keycode == 126)
		vars->y1 -= 30 / vars->zoom;
	//else if (keycode == 49)
	//	fract_init(vars);
	else if (keycode == 18)
		vars->color = 1677216;
	else if (keycode == 19)
		vars->color = 2050;
	else if (keycode == 20)
		vars->color = 265;
	clean_win(vars);
	draw_win(vars);
	return (0);
}