#include "UkladyRownan.h"



double* ElimGauss(double** A, double* b, int n)
{
	double** AB = new  double*[n];

	for (int i = 0; i < n; i++)
	{
		AB[i] = new double[n + 1];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AB[i][j] = A[i][j];
		}
		AB[i][n] = b[i];
	}

    for (int k = 0; k < n; k++) {

        int rmax = k;
        double vmax = std::abs(AB[k][k]);

        for (int i = k + 1; i < n; i++) {

            double val = std::abs(AB[i][k]);

            if (val > vmax) {
                rmax = i;
                vmax = val;
            }
        }
        
        for (int j = k; j < n + 1; j++) {
            double tmp = AB[k][j];
            AB[k][j] = AB[rmax][j];
            AB[rmax][j] = tmp;
        }
        
        for (int i = k + 1; i < n; i++) {
            double factor = AB[i][k] / AB[k][k];
            for (int j = k + 1; j < n + 1; j++) {
                AB[i][j] -= factor * AB[k][j];
            }
            AB[i][k] = 0;
        }
    }

    double* x = new double[n];
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += AB[i][j] * x[j];
        }
        x[i] = (AB[i][n] - sum) / AB[i][i];
    }



    for (int i = 0; i < n; i++) {
        delete[] AB[i];
    }
    delete[] AB;

    return x;
}