#pragma once
#include "Ortogonalizacja.h"

std::vector<std::vector<double>> Normalizacja(std::vector<std::vector<double>> S);
std::vector<std::vector<double>> Waga(std::vector<std::vector<double>> S, double(*f)(double x), int a, int b);
std::vector<double> Wspolczynniki(std::vector<std::vector<double>> S);
std::vector<double> Aproksymacja(std::vector<std::vector<double>> S, double(*f)(double x));
