#include "fractol.h"

int		trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

int		compare(char *s1, char *s2)
{
	int	l1;
	int	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 != l2)
		return (0);
	while (l1 > 0)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		l1--;
	}
	return (1);
}

int		check(char *str)
{
	if (compare(str, "julian"))
		return (0);
	if (compare(str, "mandelbrot"))
		return (1);
	return (9);
}

int		mandelbrot(comp c)
{
	int		n;
	comp	z;

	n = 0;
	z = (comp) {.real = 0, .imag = 0};
	//printf("c = %.1f%+.1fi\n", c.real, c.imag);
	while (module(z) <= 2 && n <= 80)
	{
		z = multiply(z, z);
		z = add(z, c);
		n++;
	}
	return (n);
}

int		julian(comp c)
{
	int		n;
	comp	z;

	z = (comp) {.real = -0.7795, .imag = 0.134};
	while (module(c) <= 2 && n <= 80)
	{
		c = multiply(c, c);
		c = add(c, z);
		n++;
	}
	return (n);
}

int		create_color(int m)
{
	int		color;

	color = 0;
	if (m < 5)
		color = 5918708;
	else if (m >= 5 && m <= 15)
		color = 6098420;
	else if (m > 15 && m <= 20)
		color = 255 - (m * 255/50);
	else if (m > 20 && m <= 40)
		//color = trgb(255 - (int)(m * 255 / 80), 255 - (int)(m * 255 / 80), 255 - (int)(m * 255 / 80), 255 - (int)(m * 255 / 80));
		color = 150932980;
	else if (m > 40 && m <= 50)
		//color = trgb(255 - (int)(m * 255 / 800), 255 - (int)(m * 255 / 800), 255 - (int)(m * 255 / 800), 255 - (int)(m * 255 / 800));
		color = 255 - (m * 255/80);
	else if (m > 50 && m <= 80)
		color = 255 - (m * 255/256);
	else if (m > 80)
		color = 0;
	//	color = 255 - (int)(m * 255 / 80);
	return (color);
}

int	close(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

int	zoom(int button, int x, int y, t_vars *vars)
{
	printf("x %d\n, y %d\n, but %d\n", x, y, button);
	return (0);
}
