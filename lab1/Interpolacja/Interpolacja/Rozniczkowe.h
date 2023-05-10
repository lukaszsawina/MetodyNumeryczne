#pragma once
#include <math.h>


double Euler(double (*f)(double x, double y), double ya, double a, double b, int n);
double EulerHoena(double (*f)(double x, double y), double ya, double a, double b, int n);
double ZmodyfikowanyEuler(double (*f)(double x, double y), double ya, double a, double b, int n);
double RungegoKutty(double (*f)(double x, double y), double ya, double a, double b, int n);