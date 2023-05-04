#ifndef _NEWTON_H
#define _NEWTON_H

#include <cmath>
#include <iostream>

typedef double (*single_variable_function)(double x);
 

double newton(double x0, single_variable_function f, single_variable_function df, double tol, int max);



#endif 