#include "pch.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	
	float a, b, c, x1, x2, dx;
	printf("\n Введите значение параметра a: ");
	scanf_s("%f",&a);
	printf("\n Введите значение параметра b: ");
	scanf_s("%f", &b);
	printf("\n Введите значение параметра c: ");
	scanf_s("%f", &c);
	printf("\n Введите значение параметра x1: ");
	scanf_s("%f", &x1);
	printf("\n Введите значение параметра x2: ");
	scanf_s("%f", &x2);

	while (x1 >= x2) {
		printf("\n Неверное значение границ интервала!");
		printf("\n Введите значение параметра x1: ");
		scanf_s("%f", &x1);
		printf("\n Введите значение параметра x2: ");
		scanf_s("%f", &x2);
	}

	printf("\n Введите значение шага табуляции dx: ");
	scanf_s("%f", &dx);

	float t = fabsf(x2 - x1);
	while (dx >= t || dx <=0) {
		printf("\n Неверное значение шага табуляции!");
		printf("\n Введите значение шага табуляции dx: ");
		scanf_s("%f", &dx);
	}
	
	int n;
	n = 0;

	printf("\n ________________");
	printf("\n |  x  |  F(x)  |");
	printf("\n |_____|________|");

	float x, F;
	x = x1;
	while (x < x2) {
		if (x<0 && b!=0) {
			F = (-1 * a)*(x*x) + b;
			printf("\n |  %f  |  %f  |", x, F);
		}
		else if (x>0 && b==0) {
			if (x != c) {
				F = x / (x - c)+5.5;
				printf("\n |  %f  |  %f  |", x, F);

			}
			else printf("\n |  %f  |  error  |", x);
		
		}
		else {
			if (c != 0) {
				F = (-1 * x) / c;
				printf("\n |  %f  |  %f  |", x, F);
			}
			else {
				printf("\n |  %f  |  error  |", x);
			}
		}

		x = x + dx;
		n++;

		if ((n%10==0) && (x<x2)) {
			system("pause");
			system("cls");

			printf("\n ________________");
			printf("\n |  x  |  F(x)  |");
			printf("\n |_____|________|");
		}
	}
	
	system("pause");
	return 0;

}

