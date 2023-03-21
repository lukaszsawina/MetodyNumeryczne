#include <iostream>
#include <math.h>

#include "Interpolacja.h"
#include "Kwadratura.h"

double fun_tryg(double x)
{
	return pow(x, 2) * pow(sin(x),3);
}

double fun_exp(double x)
{
	return exp(pow(x, 2)) * (x - 1);
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

	//std::cout << metoda_trapezow_horner(&Horner_PostacNaturalna, an, xn, 10, 5) << std::endl;

	//
	//	Newton-Cotes wzor trapezów
	//
	std::cout << "Newton-Cotes wzor trapezow: 10 000 przedzialow" << std::endl;
	std::cout << NC_wzor_trapezow(&fun_tryg, 4.5, 0, 10000) << std::endl;
	std::cout << NC_wzor_trapezow(&fun_exp, 2, -2, 10000) << std::endl;

	std::cout << std::endl;

	std::cout << "Newton-Cotes wzor trapezow: 1 000 000 przedzialow" << std::endl;
	std::cout << NC_wzor_trapezow(&fun_tryg, 4.5, 0, 1000000) << std::endl;
	std::cout << NC_wzor_trapezow(&fun_exp, 2, -2, 1000000) << std::endl;

	std::cout << std::endl;

	//
	//	Newton_Cotes wzor Simpsona
	//
	std::cout << "Newton-Cotes wzor Simpsona: 10 000 przedzialow" << std::endl;
	std::cout << NC_wzor_Simpsona(&fun_tryg, 4.5, 0, 10000) << std::endl;
	std::cout << NC_wzor_Simpsona(&fun_exp, 2, -2, 10000) << std::endl;

	std::cout << std::endl;

	std::cout << "Newton-Cotes wzor Simpsona: 1 000 000 przedzialow" << std::endl;
	std::cout << NC_wzor_Simpsona(&fun_tryg, 4.5, 0, 1000000) << std::endl;
	std::cout << NC_wzor_Simpsona(&fun_exp, 2, -2, 1000000) << std::endl;

	return 0;
}

