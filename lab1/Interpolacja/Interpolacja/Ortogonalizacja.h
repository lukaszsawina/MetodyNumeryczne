#pragma once
#include<iostream>
#include "Kwadratura.h"
#include "Interpolacja.h"
#include<vector>
#include<math.h>


// Funkcja pomocnicza do obliczenia iloczynu skalarnego dwóch wielomianów
double iloczynSkalarny(std::vector<double> p, std::vector<double> q, double a, double b);

std::vector<std::vector<double>> Grama_Schmidta(std::vector<std::vector<double>> S, double a, double b, int n);

double wartWielomianu(std::vector<double> p, double x);