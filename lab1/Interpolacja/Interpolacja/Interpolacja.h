#pragma once

double Horner_PostacNaturalna(double* an, double x, int n);
double rekuHorner_PostacNewtona(double* an, double* xn, int x, int n);

double lagrange(double* xn, double* yn, double x, int n);

double newton_lagrange(double* xn, double* yn, double x, int n);
double iloraz_roznicowy(double* xn, double* yn, int n);
double pk(double* xn, double x, int n);