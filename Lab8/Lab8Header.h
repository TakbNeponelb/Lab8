#pragma once

double half_div_method(double a, double b, double eps, int* number, double (*f)(double));
double chord_method(double a, double b, double eps, int* number, double (*f)(double));
double f1(double x);
double f2(double x);
