#include <iostream>
#include "Interpolacja.h"

int main()
{
	std::cout << "Wartosc wielomianu w postaci naturalnej przy pomocy schematu Hornera" << std::endl;
	//a3, a2, a1, a0
	double an[] = {(double)1/2, (double)4 / 3, (double) - 13 / 6, -2};

	std::cout << Horner_PostacNaturalna(an, -4, 4) << std::endl;
	std::cout << Horner_PostacNaturalna(an, -1, 4) << std::endl;
	std::cout << Horner_PostacNaturalna(an, 0, 4) << std::endl;
	std::cout << Horner_PostacNaturalna(an, 2, 4) << std::endl;


	std::cout << "Wartosc wielomianu w postaci Newtona przy pomocy schematu Hornera rekurencyjnie" << std::endl;
	//b3,b2,b1,b0
	double bn[] = { (double)1/2, (double)-7 / 6 , (double) 5 / 3, (double)-4 };
	//x3,x2,x1
	double xn[] = { (double)0, (double)-1, (double)-4};

	std::cout << rekuHorner_PostacNewtona(bn, xn, -4, 3) << std::endl;
	std::cout << rekuHorner_PostacNewtona(bn, xn, -1, 3) << std::endl;
	std::cout << rekuHorner_PostacNewtona(bn, xn, -0, 3) << std::endl;
	std::cout << rekuHorner_PostacNewtona(bn, xn, 2, 3) << std::endl;

	return 0;
}

