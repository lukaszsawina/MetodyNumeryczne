#include <iostream>
#include "Kwadratura.h"
#include "Interpolacja.h"

double metoda_trapezow_horner(double* an, double* xn, int n, int m)
{
	double output = 0;
	double temp = 0;

	for (int i = 0; i < n-1; i++)
	{
		temp = ((xn[i + 1] - xn[i]) / 2);
		output += (temp * Horner_PostacNaturalna(an, xn[i], m) + temp* Horner_PostacNaturalna(an, xn[i+1], m));
	}

	return output;
}

double NC_wzor_trapezow(double (*f)(double x), double up, double down, int n)
{
	double output = 0;
	double area = 0;
	double offset = fabs((up - down) / n);
	double temp = (offset / 2);
	double j = down;

	for (int i = 0; i < n - 1; i++)
	{
		output += temp * (f(j) + f(j + offset));
		j += offset;
	}

	return output;
}

double NC_wzor_Simpsona(double (*f)(double x), double up, double down, int n)
{
	double output = 0;
	double area = 0;
	double offset = (up - down) / n;
	double temp = (offset / 6);
	double j = down;
	for (int i = 0; i < n - 1; i++)
	{
		area = temp*( f(j) + 4*f((2*j + offset)/2) + f(j + offset));
		output += area;
		j += offset;
	}

	return output;
}

