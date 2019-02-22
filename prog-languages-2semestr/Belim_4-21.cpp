#include "pch.h"
#include <stdio.h>
#include <cstdlib>
#include <locale.h>

void print_array(int* A, int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", A[i]);
	};
	printf("\n");
}

int sum_even(int* A, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			sum += A[i];
		}
	}
	return sum;
}

int last_zeroIndex(int* A, int n) {
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (A[i] == 0) index = i;
	}
	if (index == -1) {
		return -1;
	}
	else return index;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int A[50];
	int n;
	printf("\n Введите количество элементов для массива A: ");
	scanf_s("%i", &n);

	for (int i = 0; i < n; i++) {
		printf("\n Введите элемент номер %i: ", i);
		scanf_s("%i", &A[i]);
	}

	printf("\n Исходный массив: ");
	void print_array(int* A, int n);
	print_array(A, n);

	int sum_even(int* A, int n);
	printf("\n Сумма элементов, индексы которых четные: %i \n", sum_even(A, n));
	
	int last_zeroIndex(int* A, int n);
	if (last_zeroIndex(A, n) != -1) {
		printf("\n Индекс последнего нулевого элемента: %i \n", last_zeroIndex(A, n));
	}
	else printf("Нулевые элементы отсутствуют!");

	printf("\n");
	system("pause");

	return 0;
}
/* void change_indexes(int* A, int n) {
	int a1;
	for (int i = 0; i < n; i++) {
		if (i == n - 1)break;
		a1 = A[i + 1];
		A[i + 1] = A[i];
		A[i] = a1;
	};
	printf("\n Массив со смещением: ");
	void output(int* A, int n);
	output(A, n);

} */
