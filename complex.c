#include "fractol.h"

comp	add(comp a, comp b)
{
	comp	ret;

	ret.real = a.real + b.real;
	ret.imag = a.imag + b.imag;
	return (ret);
}

comp 	multiply(comp a, comp b)
{
	comp	ret;

	ret.real = a.real * b.real - a.imag * b.imag;
	ret.imag = a.real * b.imag + a.imag * b.real;
	return (ret);
}

double	module(comp a)
{
	double	ret;

	ret = sqrt(a.real * a.real + a.imag * a.imag);
	return (ret);
}
