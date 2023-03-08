#include <iostream>


double zad1_horner(double* an, double x, int n);
double zad2_rekur_horner(double* an, double* xn, int x, int n);

int main()
{
	//double an[] = {(double)1/2, (double)4 / 3, (double) - 13 / 6, -2};

	//std::cout << zad1_horner(an, -4, 4) << std::endl;
	//std::cout << zad1_horner(an, -1, 4) << std::endl;
	//std::cout << zad1_horner(an, 0, 4) << std::endl;
	//std::cout << zad1_horner(an, 2, 4) << std::endl;

	//a3,a2,a1,a0
	double an[] = { (double)1/2, (double)-7 / 6 , (double) 5 / 3, (double)-4 };
	//x3,x2,x1
	double xn[] = { (double)0, (double)-1, (double)-4};

	std::cout << zad2_rekur_horner(an, xn, -4, 3) << std::endl;
	std::cout << zad2_rekur_horner(an, xn, -1, 3) << std::endl;
	std::cout << zad2_rekur_horner(an, xn, -0, 3) << std::endl;
	std::cout << zad2_rekur_horner(an, xn, 2, 3) << std::endl;

	return 0;
}

double zad1_horner(double* an, double x, int n)
{
	double wi = an[0];

	for (int i = n - 1, j=1; i > 0; i--, j++)
		wi = wi * x + an[j];

	return wi;
}

double zad2_rekur_horner(double* an, double* xn, int x, int n)
{
	if (n == 0)
		return an[0];
	else
		return zad2_rekur_horner(an, xn, x, n - 1) * (x-xn[n-1]) + an[n];
}