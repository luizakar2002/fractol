#include "fractol.h"

int		mouse_julia(int x, int y, t_vars *vars)
{
	if (vars->fractal == 0)
	{
		vars->c_r = (x * 2) / (double)vars->width;
		vars->c_i = (y * 2 - 800) / (double)vars->width;
		draw_win(vars);
	}
	return (0);
}

int	close(int keycode)
{
	if (keycode == 53)
		exit(1);
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
	draw_win(vars);
	return (0);
}

void	show_inst(t_vars *vars)
{
	clean_win(vars);
	if (vars->fractal == 3)
	{
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 200, vars->height / 2 - 110, 255, "Usage: ./fractol julia");
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 200, vars->height / 2 - 90, 255, "       ./fractol mandelbrot");
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 200, vars->height / 2 - 70, 255, "       ./fractol burningship");
	}
	else
	{
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 200, vars->height / 2 - 110, 255, "Colors:                 1, 2, 3");
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 200, vars->height / 2 - 90, 255, "Up, Down, Left, Right:  arrows");
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 200, vars->height / 2 - 70, 255, "Close:                  ESC");
		mlx_string_put(vars->mlx, vars->win, vars->width / 2 - 200, vars->height / 2 - 50, 255, "Back:                   Enter");
	}
	
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
	else if (keycode == 18)
		vars->color = 1677216;
	else if (keycode == 19)
		vars->color = 2050;
	else if (keycode == 20)
		vars->color = 265;
	else if (keycode == 4) //H
	{
		show_inst(vars);
		return (0);
	}
	else if (keycode == 36) //enter
		clean_win(vars);
	draw_win(vars);
	return (0);
}