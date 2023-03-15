#include <iostream>
#include "Interpolacja.h"

int main()
{
	//
	//	Postaæ naturalna
	// 
	//std::cout << "Wartosc wielomianu w postaci naturalnej przy pomocy schematu Hornera" << std::endl;
	////a3, a2, a1, a0
	//double an[] = {0.4, 5, -6, -2,55};

	////std::cout << Horner_PostacNaturalna(an, -1.9, 5) << std::endl;
	////std::cout << Horner_PostacNaturalna(an, -1, 4) << std::endl;
	////std::cout << Horner_PostacNaturalna(an, 0, 4) << std::endl;
	////std::cout << Horner_PostacNaturalna(an, 2, 4) << std::endl;

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
	//std::cout << rekuHorner_PostacNewtona(bn, xn, 2, 3) << std::endl;

	//
	//	Interpolacja Lagrange'a
	// 
	//std::cout << "Interpolacja Lagrange'a " << std::endl;
	//double xn[] = {-2, -1.9, -1.8, -1.7, -1.6};
	//double yn[] = {1.4, 8.05784, 14.19904, 19.83584, 24.98144};

	//std::cout << lagrange(xn, yn, -1.75, 5) << std::endl;


	//
	//	Iloraz ró¿nicowy
	//
	std::cout << "Iloraz roznicowy" << std::endl;
	double xn[] = {0,2,3,4,6};
	double yn[] = {1,3,2,5,7};
	int k = 5;
	std::cout << iloraz_roznicowy(xn, yn, k) << std::endl;

	return 0;
}

