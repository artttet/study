#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "math.h"
#include "myscan.cpp"



/*
	ВНИМАНИЕ!

	Пожалуйста, не повторяйте мой способ проверки на ввод при помощи функции read_number, которая хранится в отдельном файле myscan.cpp
	Файл myscan.cpp, конечно же, желается удалить
	Всё это делается чтобы избежать палева на одинаковых лабах)

	Спасибо за внимание!
*/

int read_number(double* value, const char* promt, int size_buf, const char* mode);

void print_turn(int turn[], int count) {
	printf("\n");
	if (count == 0) {
		printf("Очередь пуста");
	}
	else {

		for (int i = 0; i < count; i++) {
			printf("%i ", turn[i]);
		}
	}
	printf("\n\n");
}

void push(int turn[], int* count, int elem) {
	if (*count == 50) {
		printf("Очередь полна.");
	}
	else {
		if (*count == 0) {
			turn[0] = elem;
			(*count)++;
		}
		else {
			for (int i = *count; i > 0; i--) {
				turn[i] = turn[i - 1];
			}
			turn[0] = elem;
			(*count)++;
		}
	}
}

int pop(int turn[], int* count) {
	int c = 0;
	for (int i = 0; i < *count; i++) c += turn[i];

	int elem = (turn[*count - 1]) * (c / *count);
	(*count)--;
	return elem;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int turn[50];
	int count = 0, status = 0;
	double key = 0, elem = 0;
	while (key != 3) {
		do {
			printf("------------------------------------------------------------------------------------------------");
			printf("\nСодержимое очереди: \n");
			print_turn(turn, count);
			printf("1.Добавить элемент в очередь.\n");
			printf("2.Извлечь элемент из начала очереди, предварительно умножив его на среднее арифмитеское элементов очереди. \n");
			printf("3.Выход из программы.\n");
			status = read_number(&key, "Выберите операцию", 1, "int");
			//printf("Key --- %i", (int)key);
			if ((int)key == 3) break;
			if ((int)key < 1 || (int)key > 2) {
				printf("\nТакой операции не сущетсвует.\n");
				status = -1;
			}
			
			if (status != 0) {
				printf("\nПопробуйте ещё раз.\n");
			}
		} while (status != 0);
		
		if ((int)key == 1) {
			do {
				status = read_number(&elem, "Введите значение элемента", 8, "int");
				if (status != 0) {
					printf("\nПопробуйте ещё раз.\n");
				}
				else push(turn, &count, (int)elem);
			} while (status != 0);
		}

		if ((int)key == 2) {
			if (count == 0) printf("\n Извлечение элемента невозможно.\n");
			else printf("\n Извлеченный элемент = %i\n", pop(turn, &count));
		}
	}
	return 0;
}






