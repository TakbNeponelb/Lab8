#include <Windows.h>
#include <stdio.h>  // printf, scanf
#include <conio.h>  // getch
#include <cmath> // Математические функции (sin cos atan exp pow и т.д.) и константа Пи - M_PI
#include <stdlib.h>
#include "Lab8Header.h"
#define _USE_MATH_DEFINES // для C++
#define M_PI 3.1415926535
#pragma warning(suppress : 4996)

double half_div_method(double a, double b, double eps, int* number, double (*f)(double))
{
	double c = (a + b) / 2;
	double a_values;
	double b_values;
	double c_values = f(c);
	int k = 1;
	while (fabs(c_values) > eps)
	{
		c = (a + b) / 2;
		a_values = f(a);
		b_values = f(b);
		c_values = f(c);
		if (a_values * c_values < 0) b = c;
		else a = c;
		++k;
	}
	*number = k;
	return c;

}




double chord_method(double a, double b, double eps, int* number, double (*f)(double))
{
	double c1 = a;
	double a_values = f(a);
	double b_values = f(b);
	double c2 = a - (a_values * (a - b)) / (a_values - b_values);
	double c_values;
	int k = 1;
	double c_ = a;
	while (fabs(c_ - c2) > eps)
	{
		a_values = f(a);
		b_values = f(b);
		c2 = a - (a_values * (a - b)) / (a_values - b_values);
		c_values = f(c2);
		if ((a_values < 0 and c_values > 0) || (a_values > 0 and c_values < 0))
		{
			b = c2;
			c_ = c1;

		}else
		{
			a = c2;
			c_ = c1;
		}
		c1 = c2;
		++k;
	}
	*number = k;
	return c2;
}


double f1(double x)
{
	double y;
	y = 1.5 - ((pow(x, 0.5) + pow(x, 1.0/3)) / exp(1.5)) - x;
	return y;
}

double f2(double x)
{
	double y;
	double x_ = (1 + x) / x;
	y = 0.5 * (2 - sin(x_) + 0.5 * log(sqrt(x))) - x;
	return y;
}
//sin(((1 + x) / x) )