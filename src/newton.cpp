#include "newton.h"


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