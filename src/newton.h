#ifndef _NEWTON_H
#define _NEWTON_H

typedef double (*single_variable_function)(double x);


double newton(int x0, single_variable_function f, single_variable_function df);


#endif 