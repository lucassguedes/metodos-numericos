#include "zero_approx.h"


double newton(double x0, single_variable_function f, single_variable_function df, double tol, int max)
{
    int it = 0;

    double x, e, div;
    for(it = 0; it < max; it++)
    {
    
        x = x0 - f(x0)/df(x0);

        e = fabs(x - x0)/fabs(x);
        if(e < tol)
            break;
        
        x0 = x;
    }

    if(it == max)
        std::cout << "Solução não obtida em " << it << " iterações.\n";
    else
        std::cout << "Solução obtida: x = " << x << std::endl;

    return x;
}

double bisection(single_variable_function f, double a, double b, double tol, int N)
{
    double fa = f(a);
    double fb = f(b);
    bool done = false;
    int i;

    if(fa*fb >= 0)
    {
        std::cout << "A função deve ter sinais opostos em a e em b!\n";
        return -1;
    }

    /*Número mínimo de iterações*/
    int niter = (int)ceil(log((b-a)/tol)/log(2));

    if(N < niter)
        std::cout << "São necessárias pelo menos " << niter << " iterações, mas N = " << N << ".\n";

    double xm = (a+b)/2;

    i = 1;

    double fxm;
    while(fabs(a-b) > tol && (!done && N != 0))
    {
        fxm = f(xm);

        if((fa * fxm) < 0)
        {
            b = xm;
            fb = fxm;
            xm = (a+b)/2;
        }else if((fxm*fb) < 0)
        {
            a = xm;
            fa = fxm;
            xm = (a+b)/2;
        }else{
            done = true;
        }

        N--;
        i++;
    }

    return xm;
}