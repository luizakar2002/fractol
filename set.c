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

int		mandelbrot(comp c, t_vars *vars)
{
	int		n;
	comp	z;

	n = 0;
	z = (comp) {.real = 0, .imag = 0};
	while (module(z) <= 2 && n < vars->max_it)
	{
		z = multiply(z, z);
		z = add(z, c);
		n++;
	}
	return (n);
}

int		julian(comp c, t_vars *vars)
{
	int		n;
	comp	z;

	n = 0;
	z = (comp) {.real = -0.7795, .imag = 0.134};
	while (module(c) <= 2 && n <= vars->max_it)
	{
		c = multiply(c, c);
		c = add(c, z);
		n++;
	}
	return (n);
}