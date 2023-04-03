#include <iostream>
#include <math.h>

#include "Interpolacja.h"
#include "Kwadratura.h"
#include "UkladyRownan.h"


double fun1(double x)
{
	return 55 - 2 * x - 6 * pow(x, 2) + 5 * pow(x, 3) + 0.4 * pow(x, 4);
}
double fun2(double x)
{
	return 1 - 2 * exp(x) - 6 * cos(x);
}
double fun3(double x)
{
	return pow(x, 2) * pow(sin(x), 3);
}
double fun4(double x)
{
	return exp(pow(x, 2)) * (x - 1);
}
double fun5(double x)
{
	return sin(1 - x) / (1 - x);
}
double fun6(double x)
{
	
	if ((1 - x) == 0)
	{
		return sin(1/1e-5);
	}
	return sin(1/(1 - x));
}
double fun7(double x)
{
	if(x == 0)
	{
		return 1;
	}
	return sin(x) / x;
}

int main()
{
	//
	//	Postaæ naturalna
	// 
	//std::cout << "Wartosc wielomianu w postaci naturalnej przy pomocy schematu Hornera" << std::endl;
	////a3, a2, a1, a0
	//double an[] = {0.4, 5, -6, -2,55};

	//std::cout << Horner_PostacNaturalna(an, -1.9, 5) << std::endl;
	//std::cout << Horner_PostacNaturalna(an, -1, 4) << std::endl;
	//std::cout << Horner_PostacNaturalna(an, 0, 4) << std::endl;
	//std::cout << Horner_PostacNaturalna(an, 2, 4) << std::endl;

	//
	//	Postaæ Newtona
	// 
	//std::cout << "Wartosc wielomianu w postaci Newtona przy pomocy schematu Hornera rekurencyjnie" << std::endl;
	////b3,b2,b1,b0
	//double bn[] = { (double)1/2, (double)-7 / 6 , (double) 5 / 3, (double)-4 };
	////x3,x2,x1
	//double xn[] = { (double)0, (double)-1, (double)-4};

	//std::cout << rekuHorner_PostacNewtona(bn, xn, -4, 3) << std::endl;
	//std::cout << rekuHorner_PostacNewtona(bn, xn, -1, 3) << std::endl;
	//std::cout << rekuHorner_PostacNewtona(bn, xn, -0, 3) << std::endl;
	//std::cout << rekuHorner_PostacNewtona(bn, xn, 2, 4) << std::endl;


	//
	//	Newton na naturalne
	//
	//std::cout << "Wspolczynniki wielomianu naturalnego z wielomianu Newtona" << std::endl;
	////b3,b2,b1,b0
	//double bn[] = { (double)1/2, (double)-7 / 6 , (double) 5 / 3, (double)-4 };
	////x3,x2,x1
	//double xn[] = { (double)0, (double)-1, (double)-4};

	//double* an = new double[4];
	////std::cout << Newton_naturalna(an, bn, xn, 4) << std::endl;


	//double bn[] = {1, -2, 1};
	//double xn[] = {0, 1, 2};
	//double* an = newton_to_natural(bn, xn, 3);
	//for (int i = 0; i < 3; i++) {
	//	std::cout << an[i] << " ";
	//}



	//
	//	Interpolacja Lagrange'a
	// 
	//std::cout << "Interpolacja Lagrange'a " << std::endl;
	// x0,x1,x2,x3,x4
	// double xn[] = {-2, -1.9, -1.8, -1.7, -1.6};
	// y0,y1,y2,y3,y4
	//double yn[] = {1.4, 8.05784, 14.19904, 19.83584, 24.98144};

	//std::cout << lagrange(xn, yn, -1.75, 5) << std::endl;


	//
	//	Iloraz ró¿nicowy
	//
	//std::cout << "Iloraz roznicowy" << std::endl;
	//// x0,x1,x2,x3,x4
	//double xn[] = {0,2,3,4,6};
	//// y0,y1,y2,y3,y4
	//double yn[] = {1,3,2,5,7};
	//int k = 5;

	//for (int j = 0; j < 5; j++)
	//	std::cout << iloraz_roznicowy(xn,yn,j+1) << std::endl;

	//
	//	Metoda trapezów z Hornerem
	//
	//double an[] = {0.4, 5, -6, -2, 55};
	//double xn[] = {-2, -1.9, -1.8, -1.7, -1.6, -1.5, -1.4, -1.3, -1.2, -1.1};

	//std::cout << metoda_trapezow_horner(an, xn, 10, 5) << std::endl;

	//
	//	Newton-Cotes wzor trapezów
	//
	//std::cout << "Wzor Trapezow" << std::endl;
	////std::cout << NC_wzor_trapezow(&fun_tryg, 4.5, 0, 1000000) << std::endl;
	std::cout.precision(10);

	//std::cout << NC_wzor_trapezow(&fun1, 2, -2, 1000000) << std::endl;
	//std::cout << NC_wzor_trapezow(&fun2, 2, -2, 1000000) << std::endl;
	//std::cout << NC_wzor_trapezow(&fun3, 4.5, 0, 2000000) << std::endl;
	//std::cout << NC_wzor_trapezow(&fun4, 2, -2, 5500000) << std::endl;
	//std::cout << NC_wzor_trapezow(&fun5, 1, 0, 5500000) << std::endl;
	//std::cout << NC_wzor_trapezow(&fun6, (1 - 1e-4), 0, 100) << std::endl;
	//std::cout << NC_wzor_trapezow(&fun7, 1, 0, 1000000) << std::endl;


	//std::cout << std::endl;
	//std::cout << std::endl;


	//
	//	Newton_Cotes wzor Simpsona
	//
	//std::cout << "Wzor Simpsona" << std::endl;
	////std::cout << NC_wzor_Simpsona(&fun_tryg, 4.5, 0, 1000000) << std::endl;
	////std::cout << NC_wzor_Simpsona(&fun_exp, 2, -2, 1000000) << std::endl;

	//std::cout << NC_wzor_Simpsona(&fun1, 2, -2, 1000000) << std::endl;
	//std::cout << NC_wzor_Simpsona(&fun2, 2, -2, 1000000) << std::endl;
	//std::cout << NC_wzor_Simpsona(&fun3, 4.5, 0, 2000000) << std::endl;
	//std::cout << NC_wzor_Simpsona(&fun4, 2, -2, 5500000) << std::endl;
	//std::cout << NC_wzor_Simpsona(&fun5, 1, 0, 5500000) << std::endl;
	//std::cout << NC_wzor_Simpsona(&fun6, 1 - 1e-4, 0, 1000000) << std::endl;
	//std::cout << NC_wzor_Simpsona(&fun7, 1, 0, 1000000) << std::endl;

	//
	//	Metoda Gaussa
	//
	//std::cout << "Metoda Gaussa" << std::endl;
	//std::cout << CalkowanieGaussa(&fun1, 2, -2, 10000, 2) << std::endl;
	//std::cout << CalkowanieGaussa(&fun2, 2, -2, 10000, 2) << std::endl;
	//std::cout << CalkowanieGaussa(&fun3, 4.5, 0, 10000, 2) << std::endl;
	//std::cout << CalkowanieGaussa(&fun4, 2, -2, 10000, 2) << std::endl;
	//std::cout << CalkowanieGaussa(&fun5, 1, 0, 10000, 2) << std::endl;
	//std::cout << CalkowanieGaussa(&fun6, 1 - 1e-4, 0, 10000, 2) << std::endl;
	//std::cout << CalkowanieGaussa(&fun7, 1, 0, 10000, 2) << std::endl;


	//
	//	Eliminacja gaussa
	//
	/*int n = 8;
	double** A = new double* [n];
	double* B = new double[n];


	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = (1. / ((i+j+2.)-1.));
		}
		B[i] = 1.;
	}

	double* x =ElimGauss(A, B, n);

	for (int i = 0; i < n; i++)
		std::cout << "x" << i+1 << ": " << x[i] << " ";

	delete[]x;*/



	//
	//	Rozk³ad LU
	//
	const int n = 3;

	double A_data[n][n] = { {60,30,20},
					   {30,20,15},
					   {20,15,12}};

	double** L = new double* [n];
	double** U = new double*[n];

	double* A[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = A_data[i];
		L[i] = new double[n];
		U[i] = new double[n];
	}


	RozkladLU(A, L, U, n);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << L[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << U[i][j] << "\t";

		}
		std::cout << std::endl;

	}

	return 0;
}

