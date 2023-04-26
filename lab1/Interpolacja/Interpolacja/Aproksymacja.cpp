#include "Aproksymacja.h"


std::vector<double> DevideVec(std::vector<double> p, double q)
{
	std::vector<double> output;
	for (int i = 0; i < p.size(); i++)
		output.push_back(p[i]/q);
	return output;
}
std::vector<double> MultipVec(std::vector<double> p, double q)
{
	std::vector<double> output;
	for (int i = 0; i < p.size(); i++)
		output.push_back(p[i] * q);
	return output;
}

std::vector<std::vector<double>> Normalizacja(std::vector<std::vector<double>> S)
{
	std::vector<std::vector<double>> output;
	for (int i = 0; i < S.size(); i++)
	{
		std::vector<double> tmp = S[i];
		double norma = iloczynSkalarny(tmp, tmp, 0, 1);
		tmp = DevideVec(tmp, sqrt(norma));
		output.push_back(tmp);
	}

	return output;
}


double iloczynSkalarnyFun(std::vector<double> p, double (*f)(double x), double a, double b)
{
	double output = 0;
	const int m = 10000;
	double offset = fabs((b - a) / m);
	double temp = (offset / 2);
	double j = a;

	for (int i = 0; i < m - 1; i++)
	{
		output += (wartWielomianu(p, j) * f(j) + wartWielomianu(p, j + offset) * f(j + offset));
		j += offset;
	}
	return output * temp;
}

std::vector<std::vector<double>> Waga(std::vector<std::vector<double>> S, double(*f)(double x), int a, int b)
{
	std::vector<std::vector<double>> output;
	for (int i = 0; i < S.size(); i++)
	{
		std::vector<double> tmp = S[i];
		double waga = iloczynSkalarnyFun(tmp, f, 0, 1);
		tmp = MultipVec(tmp, waga);
		output.push_back(tmp);
	}
	return output;
}

std::vector<double> Wspolczynniki(std::vector<std::vector<double>> S)
{
	std::vector<double> output;

	for (int i = 0; i < S.size(); i++)
	{
		double a = 0;
		for (int j = 0; j < S.size(); j++)
			a += S[j][i];
		output.push_back(a);
	}

	return output;
}

std::vector<double> Aproksymacja(std::vector<std::vector<double>> S, double(*f)(double x))
{
	//Ortogonalizowanie bazy
	std::vector<std::vector<double>> Baza = Grama_Schmidta(S, 0., 1., S.size());

	//Ortonormalizowanie bazy
	std::vector<std::vector<double>> BazaOrtoNorm = Normalizacja(Baza);

	//Liczenie bazy wagowej
	std::vector<std::vector<double>> BazaWaga = Waga(BazaOrtoNorm, f, 0, 1);

	//Liczenie wspó³czynników wielomianu
	std::vector<double> Wspol = Wspolczynniki(BazaWaga);

	return Wspol;

}