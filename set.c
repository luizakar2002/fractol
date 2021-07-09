#include "fractol.h"

int		mandelbrot(float complex c)
{
	int	n;
	int	z;

	n = 0;
	z = 0;
	printf("c = %.1f%+.1fi\n", creal(c), cimag(c));
	while (cabs(z) <= 2 && n <= 80)
	{
		z = z * z + c;
		n++;
	}
	return (n);
}
