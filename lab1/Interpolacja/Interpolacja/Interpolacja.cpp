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