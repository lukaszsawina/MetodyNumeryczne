#include "Rozniczkowe.h"

double Euler(double (*f)(double x, double y), double ya, double a, double b, int n)
{
	double h = (b-a) / n;
	double output = ya;
	double xi = a;

	for (int i = 0; i < n; i++)
	{
		output = output+ h * f(xi, output);
		xi += h;
	}
	return output;

}
double EulerHoena(double (*f)(double x, double y), double ya, double a, double b, int n)
{
	double h = (b - a) / n;
	double output = ya;
	double xi = a;

	for (int i = 0; i < n; i++)
	{
		output = output + h/2 *(f(xi, output) + f(xi+h, output + h*f(xi,output)));
		xi += h;
	}
	return output;
}
double ZmodyfikowanyEuler(double (*f)(double x, double y), double ya, double a, double b, int n)
{
	double h = (b - a) / n;
	double output = ya;
	double xi = a;

	for (int i = 0; i < n; i++)
	{
		output = output + h*f(xi+h/2, output+h/2*h*f(xi, output));
		xi += h;
	}
	return output;
}

double RungegoKutty(double (*f)(double x, double y), double ya, double a, double b, int n)
{
	double h = (b - a) / n;
	double output = ya;
	double xi = a;


	for (int i = 0; i < n; i++)
	{
		double k1 = f(xi, output);
		double k2 = f(xi + h / 2, output + h / 2 * k1);
		double k3 = f(xi + h / 2, output + h / 2 * k2);
		double k4 = f(xi + h, output + h * k3);


		output = output + h/6*(k1 + 2*k2 + 2*k3 + k4);
		xi += h;
	}
	
	return output;
}