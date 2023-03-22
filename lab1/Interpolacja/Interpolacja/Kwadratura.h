#pragma once


double metoda_trapezow_horner(double* an, double* xn, int n, int m);
double NC_wzor_trapezow(double (*f)(double x), double up, double down, int n);
double NC_wzor_Simpsona(double (*f)(double x), double up, double down, int n);

double Gauss(double (*f)(double x), double up, double down, int n);
double Integrate(double (*f)(double x), double up, double down, int m, int n);