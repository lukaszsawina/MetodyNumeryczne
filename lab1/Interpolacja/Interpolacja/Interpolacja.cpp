#include <iostream>
#include "Interpolacja.h"

double Horner_PostacNaturalna(double* an, double x, int n)
{
	double wi = an[0];
	for (int i = n - 1, j = 1; i > 0; i--, j++)
		wi = wi * x + an[j];
	return wi;
}

double rekuHorner_PostacNewtona(double* an, double* xn, int x, int n)
{
	if (n == 0)
		return an[0];
	else
		return rekuHorner_PostacNewtona(an, xn, x, n - 1) * (x - xn[n - 1]) + an[n];
}

double lagrange(double* xn, double* yn, double x, int n) 
{
	double output = 0;
	double ln;

	for (int i = 0; i < n; i++)
	{
		ln = 1;
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			ln *= (x - xn[j]) / (xn[i] - xn[j]);

		}
		output += yn[i] * ln;
	}
	return output;
}

//double newton_lagrange(double* xn, double* yn, double x, int n)
//{
//	if (n == 0)
//		return 1;
//	else
//		return newton_lagrange(xn, yn, x, n - 1) + iloraz_roznicowy(xn, yn, n) * pk(xn, x, n);
//}

double iloraz_roznicowy(double* xn, double* yn, int n)
{
	double wynik = 0;
	double mian;

	for (int i = 0; i < n; i++)
	{

		mian = 1;
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			mian *= (xn[i] - xn[j]);
		}
		wynik += (yn[i]/mian);
	}
	return wynik;
}

double pk(double* xn, double x, int n)
{
	double output = 1;
	for (int i = 0; i < n; i++)
		output *= (x - xn[i]);

	return output;
}