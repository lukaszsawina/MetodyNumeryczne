#include "RownaniaNieliniowe.h"

const double EPS0 = 0.0000000001; // dok³adnoœæ porównania z zerem
const double EPSX = 0.0000000001; // dok³adnoœæ wyznaczenia pierwiastka

double fp(double (*f)(double x), double x)
{
    return (f(x + EPSX) - f(x)) / EPSX;
}

double MetodaNewtona(double (*f)(double x), double a, double b)
{
    int i = 0; 
    double x = a;

    while (fabs(f(x)) > EPS0)
    {
        x = x - (f(x) / fp(f,x));
        i++;
    }


    return x;
}

double regula_falsi(double (*f)(double x), double a, double b)
{
    double x = a;
    double x1 = b;
    double x2 = a;

    do {
        x = x1;
        x1 = x2;
        x2 = x - f(x)*(x - x1) / (f(x) - f(x1)) ;
    } while (fabs(f(x2)) > EPS0);

    return x2;


}

double Pegaza(double (*f)(double x), double a, double b)
{
    double x = a;
    double x1 = b;
    double x2 = a;

    do {
        x = x1;
        x1 = x2;
        x2 = x - f(x) * (x - x1) / (f(x) - f(x1));
        if (fabs(f(x2)) < EPS0) break;


        if (f(x1) * f(x2) < 0)
        {
            x = x1;
            x1 = x2;
            continue;
        }

        if (f(x1) * f(x2) < 0)
        {
            x2 = f(x) * f(x2) / (f(x) - f(x2));
            x1 = x2;
        }

        if (fabs(x2 - x1) < EPS0)
        {
            if (f(x1) < f(x2))
                return x1;
            return x2;
        }

    } while (fabs(f(x2)) > EPS0);

    return x2;
}

double Bisekcja(double (*f)(double x), double a, double b)
{
    return 0;
}