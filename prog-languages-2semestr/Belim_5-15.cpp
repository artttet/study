#include "stdafx.h"

#include <stdio.h>
#include <locale.h>
#include <cstdlib>
#include <malloc.h>

float** read_matr(char* input, int* n) {
	FILE* in_file;
	int size;

	in_file = fopen(input, "r");
	if (in_file != NULL) {
		fscanf(in_file, "%i", &size);
		*n = size;
	}
	else {
		printf("\n Файл не найден!");
		return 0;
	}

	float** A = (float**)malloc(size * sizeof(float*));
	for (int i = 0; i < size; i++) {
		*(A+i) = (float*)malloc(size * sizeof(float));
	};

	printf("\n");

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fscanf(in_file, "%f", &*(*(A+i)+j));
		};
	};

	fclose(in_file);
	return A;
}

void print_matr(float** M, int n) {
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf(" %5.3f ", *(*(M+i)+j));
		}
		printf("\n");
	}
}

float** calc_B(int n) {
	float** B = (float**)malloc(n * sizeof(float*));

	for (int i = 0; i < n; i++) {
		*(B+i) = (float*)malloc(n * sizeof(float));
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(*(B+i)+j) = 1 / (float)(i + j + 2);
		};
	};
	return B;
}

float** calc_C(float** A, float** B, int n) {

	//add_E............................................
	float** E = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		*(E+i) = (float*)malloc(n * sizeof(float));
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				*(*(E+i)+j) = 1;
			}
			else *(*(E+i)+j) = 0;
		};
	};
	//...................................................

	float** C = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		*(C+i) = (float*)malloc(n * sizeof(float));
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(*(C+i)+j) = (7 * *(*(B+i)+j)) - (3 * *(*(A+i)+j) + *(*(E+i)+j));
		};
	};
	free(A);
	free(B);
	free(E);
	return C;
}

void write_matr(char* output_name, float** C, int n) {
	char per = '\n';
	FILE* out_file;
	out_file = fopen(output_name, "w");
	for (int i = 0; i < n; i++) {
		//fprintf(out_file, "%f ", *C[i]);
		for (int j = 0; j < n; j++) {
			fprintf(out_file, "%5.3f ", *(*(C+i)+j));
		};
		fprintf(out_file, "%c", per);
	};
	fclose(out_file);
	free(C);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char *input_name, *output_name;
	input_name = (char*)malloc(20 * sizeof(char));
	output_name = (char*)malloc(20 * sizeof(char));
	int n;
	float** A;
	float** B;
	float** C;

	printf("\n Введите имя файла, в котором хранится матрица А: ");
	scanf("%s", input_name);

	while (read_matr(input_name, &n) == 0) {
		printf("\n Введите имя файла, в котором хранится матрица А: ");
		scanf("%s", input_name);
	}

	A = read_matr(input_name, &n);
	printf("\n Матрица A: \n");
	print_matr(A, n);

	B = calc_B(n);
	printf("\n Матрица B: \n");
	print_matr(B, n);

	C = calc_C(A, B, n);
	printf("\n Матрица C: \n");
	print_matr(C, n);

	printf("\n");

	printf("\n Введите имя файла для записи матрицы С: ");
	scanf("%s", output_name);
	write_matr(output_name, C, n);

	system("pause");
	return 0;
}

