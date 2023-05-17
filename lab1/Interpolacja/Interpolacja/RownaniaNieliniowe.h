#pragma once
#include <iostream>

double MetodaNewtona(double (*f)(double x), double a, double b);
double regula_falsi(double (*f)(double x), double a, double b);
double Pegaza(double (*f)(double x), double a, double b);
double Bisekcja(double (*f)(double x), double a, double b);

