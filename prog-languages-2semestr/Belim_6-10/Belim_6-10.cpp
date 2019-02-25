#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <cstdlib>

void delete_char(char* str, char c) {
	while (strchr(str, c)) {
		int pos = strchr(str, c) - str;
		int len = strlen(str);
		for (int i = pos; i < len; i++) {
			str[i] = str[i + 1];
			if (i == len - 1) {
				str[i] = '\0';
			}
		}
	}
}

char* to_change(char* str) {
	char* output_file_str = str;
	const char* alphabet = "абвгдеёжзийклмноп";
	for (int i = 0; i < strlen(alphabet); i++) {
		delete_char(output_file_str, alphabet[i]);
	}
	return output_file_str;
}

int main()
{
	char* inFile_str = new char[128];
	char* input_name = new char[64];
	char* output_name = new char[64];
	FILE* input_file;
	FILE* output_file;

	setlocale(LC_ALL, "Russian");

	printf("\n Введите имя файла с расширением '.txt': ");
	scanf("%s", input_name);

	while (!strstr(input_name, ".")) {
		printf("\n Не указано расширение!");
		printf("\n Введите имя файла с расширением '.txt': ");
		scanf("%s", input_name);
	}	
	while (!strstr(input_name, ".txt")) {
		printf("\n Указано неверное расширение!");
		printf("\n Введите имя файла с расширением '.txt': ");
		scanf("%s", input_name);
	}
	
	input_file = fopen(input_name, "r");
	while (input_file == NULL) {
		printf("\n Файл не найден!");
		printf("\n Введите имя файла с расширением '.txt': ");
		scanf("%s", input_name);
		while (!strstr(input_name, ".")) {
			printf("\n Не указано расширение!");
			printf("\n Введите имя файла с расширением '.txt': ");
			scanf("%s", input_name);
		}
		while (!strstr(input_name, ".txt")) {
			printf("\n Указано неверное расширение!");
			printf("\n Введите имя файла с расширением '.txt': ");
			scanf("%s", input_name);
		}
		input_file = fopen(input_name, "r");
	}

	// Из имя.txt в имя.dat
	output_name = input_name;
	output_name[strlen(input_name) - 3] = '\0';
	strcat(output_name, "dat");

	output_file = fopen(output_name, "w");
	fgets(inFile_str, 128, input_file);
	fputs(to_change(inFile_str), output_file);

	fclose(input_file);
	if(output_file != NULL) fclose(output_file);

	system("pause");
	return 0;
}