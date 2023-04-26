#include "Ortogonalizacja.h"

double wartWielomianu(std::vector<double> p, double x)
{
	double output = 0;
	for (int i = 0; i < p.size(); i++)
		output += p[i] * pow(x,i);
	return output;
}

double iloczynSkalarny(std::vector<double> p, std::vector<double> q, double a, double b)
{

	double output = 0;
	const int m = 10000;
	double offset = fabs((b - a) / m);
	double temp = (offset / 2);
	double j = a;

	for (int i = 0; i < m - 1; i++)
	{
		output += temp * (wartWielomianu(p, j)* wartWielomianu(q, j) + wartWielomianu(p, j+offset) * wartWielomianu(q, j+offset));
		j += offset;
	}
	return output;
}

std::vector<double> proj(std::vector<double> p, std::vector<double> q, double a, double b)
{
	std::vector<double> output;
	double wynikDzielenia = iloczynSkalarny(p, q, a, b) / iloczynSkalarny(q, q, a, b);
	for (int i = 0; i < p.size(); i++)
		output.push_back(q[i] * wynikDzielenia);
	return output;
}

std::vector<double> SubtractVec(std::vector<double> p, std::vector<double> q)
{
	std::vector<double> output;
	for (int i = 0; i < p.size(); i++)
		output.push_back(p[i] - q[i]);
	return output;
}

std::vector<std::vector<double>> Grama_Schmidta(std::vector<std::vector<double>> S, double a, double b, int n)
{
	std::vector<std::vector<double>> Baza;

	//Pierwszy wiersz przepisujemy
	Baza.push_back(S[0]);

	for (int i = 1; i < n; i++)
	{
		//Tymczasowa zmienna z inputu przepisana 
		std::vector<double> tmp = S[i];
		for (int j = 0; j < i; j++)
			tmp = SubtractVec(tmp,proj(S[i], Baza[j], a, b));

		Baza.push_back(tmp);
	}

	return Baza;
}