#include <iostream>
#include "zero_approx.h"


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


/*Função de disponibilidade de água por pessoa*/
double consumption(double t)
{
    double P0 = 70000;
    double D = 20;

    double beta = 0.03;
    double sigma = 0.02;

    return P0 * D * exp((beta-sigma)*t);
}

double water(double t)
{
    double W0 = 2*pow(10,6);

    double alpha = 0.6;
    double efficiency = 0.6;
    double A = 2000;

    return W0 + (250*cos((M_PI/6)*t - (M_PI/6)) + 253) * efficiency * A - consumption(t);
}

double df_water(double t)
{
    return 78539.81633*cos(0.52359*t) - 14000*exp((0.01*t)) - 136034.95*sin(0.52359*t);
}



int main(void)
{
    double x0 = 42;
    double tol = 1e-3;
    double nmax = 100;

    clock_t begin_time, end_time;


    std::cout << "1. Newton:\n";
    std::cout << "Estimativa inicial: " << x0 << std::endl;
    begin_time = clock();
    double xm = newton(x0, water, df_water, tol, nmax);
    end_time = clock();

    std::cout << "TEMPO (Newton): " << (double)(end_time - begin_time) / CLOCKS_PER_SEC << std::endl;

    std::cout << "2. Bisseção:\n";
    begin_time = clock();
    xm = bisection(water, 0, 45, 1e-3, 40);
    end_time = clock();
    std::cout << "Solução encontrada: " << xm << std::endl;
    std::cout << "TEMPO (Bisseção): " << (double)(end_time - begin_time) / CLOCKS_PER_SEC << std::endl;

    double xa = 35.0;
    double xb = 42.0;


    std::cout << "3. Secante:\n";
    begin_time = clock();
    xm = secant(xa, xb, water, tol, nmax);
    end_time = clock();
    std::cout << "TEMPO (Secante): " << (double)(end_time - begin_time) / CLOCKS_PER_SEC << std::endl;


    return 0;
}