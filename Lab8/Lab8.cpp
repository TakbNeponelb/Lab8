//---------------------------------------------------------------------------
#include <Windows.h>
#include <stdio.h>  // printf, scanf
#include <conio.h>  // getch
#include <cmath> // Математические функции (sin cos atan exp pow и т.д.) и константа Пи - M_PI
#include <stdlib.h>
#include "Lab8Header.h"
#define _USE_MATH_DEFINES // для C++
#pragma warning(suppress : 4996)
//--------------------------------------------------------------------------


void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double a;
	double b;
	double eps = 0.1;

	int n;
	int number;
	double x;

	printf("Введите n (0<n<=10): ");
	scanf_s("%d", &n);
	printf("Введите a,b (0<a<b<2): ");
	scanf_s("%lf", &a);
	scanf_s("%lf", &b);

	double a1 = a;
	double b1 = b;

	if (n > 10 || n <= 0 || b < a || b > 2 || a < 0)
	{
		printf("Неправильно введены данные!!!");
		return;
		
	}
	else if (f1(a) * f1(b) >= 0)
	{
		printf("Функция №1\n");
		printf("Функция в этих интервалах не пересекает ось абсцисс!!!");
	}
	else
	{
		printf("Функция №1\n");
		printf("Точность\t\t\tМетод хорд\t\t\t\tПополам\n");
		printf("\t\t\tкорень\t\tкол-во итераций\t\tкорень\t\tкол-во итераций\n");
		for (int i = 0; i <= n; ++i)
		{
			x = chord_method(a, b, eps, &number, f1);
			printf("%10.11lf\t\t%10.11lf\t\t%4d\t\t", eps, x, number);

				x = half_div_method(a, b, eps, &number, f1);
			printf("%10.11lf\t\t%4d\n", x, number);

			eps /= 10;
		}

		if (f2(a) * f2(b) >= 0)
		{
			printf("\nФункция №2\n");
			printf("Функция в этих интервалах не пересекает ось абсцисс!!!");
		}
		else
		{
			printf("\n\nФункция №2\n");
			printf("Точность\t\t\tМетод хорд\t\t\t\tПополам\n");
			printf("\t\t\tкорень\t\tкол-во итераций\t\tкорень\t\tкол-во итераций\n");
			eps = 0.1;
			for (int i = 0; i <= n; ++i)
			{
				x = chord_method(a, b, eps, &number, f2);
				printf("%10.11lf\t\t%10.11lf\t\t%4d\t\t", eps, x, number);

				x = half_div_method(a, b, eps, &number, f2);
				printf("%10.11lf\t\t%4d\n", x, number);

				eps /= 10;
			}
		}

	
	}
	printf("\n\n");
	
	

	
	_getch();
	return; //выход из main()
}
//---------------------------------------------------------------------------

