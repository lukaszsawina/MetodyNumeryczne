#pragma once

double Horner_PostacNaturalna(double* an, double x, int n);
double rekuHorner_PostacNewtona(double* bn, double* xn, int x, int n);
double* Newton_naturalna(double* bn, double* xn, int n);


double lagrange(double* xn, double* yn, double x, int n);
double iloraz_roznicowy(double* xn, double* yn, int n);