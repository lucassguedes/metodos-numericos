#include <iostream>
#include "newton.h"


using namespace std;

/*As funções f e sua derivada df são exemplos para testes*/
double f(double x)
{
    return -0.9 * (x*x) + 1.7*x + 2.5;
} 

double df(double x)
{
    return -1.8*x + 1.7;
}

int main(void)
{
    double x0 = 0;
    double tol = 1e-3;
    double nmax = 100;


    std::cout << "Estimativa inicial: " << x0 << std::endl;
    double xm = newton(x0, &f, &df, tol, nmax);

    return 0;
}