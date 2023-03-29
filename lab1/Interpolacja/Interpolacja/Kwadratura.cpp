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
	double offset = (up - down) / n;
	double temp = (offset / 6);
	double j = down;
	for (int i = 0; i < n - 1; i++)
	{
		output += temp * (f(j) + 4 * f((2 * j + offset) / 2) + f(j + offset));
		j += offset;
	}

	return output;
}

double Gauss(double (*f)(double x), double up, double down, int n) 
{
	double output = 0.0;
	double nn = n;
	double* An = new double[nn];
	double* xn = new double[nn];

	switch (n)
	{
	case 2:
		xn[0] = -0.577350;
		xn[1] = 0.577350;
		An[0] = An[1] = 1;
		break;
	case 3:
		xn[0] = -0.774597;
		xn[1] = 0;
		xn[2] = 0.774597;
		An[0] = An[2] = (double)5 / 9;
		An[1] = (double)8 / 9;
		break;
	case 4:
		xn[0] = -0.861136;
		xn[1] = -0.339981;
		xn[2] = 0.339981;
		xn[3] = 0.861136;
		An[0] = An[3] =0.347855;
		An[1] = An[2]= 0.652145;
		break;
	case 5:
		xn[0] = -0.906180;
		xn[1] = -0.538469;
		xn[2] = 0;
		xn[3] = 0.538469;
		xn[4] = 0.906180;
		An[0] = An[4] = 0.236927;
		An[1] = An[3] = 0.478629;
		An[2] = 0.568889;
		break;
	default:
		return 0;
	}

	double alfa = (up - down) / (1.0 - (-1.0));
	double beta = (down * 1.0 - up * (-1.0)) / (1.0 - (-1.0));

	for (int i = 0; i < nn; i++)
		output += An[i] * f(alfa*xn[i]+beta);

	output *= alfa;

	delete[] An;
	delete[] xn;
	return output;
}


double CalkowanieGaussa(double (*f)(double x), double up, double down, int m, int n)
{
	double output = 0;
	double offset = (up - down) / m;
	double j = down;

	if (n < 2)
		n = 2;
	else if (n > 5)
		n = 5;

	for (int i = 0; i < m - 1; i++)
	{
		output += Gauss(f, j+offset, j, n);
		j += offset;
	}

	return output;
}