#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <locale.h>
#include <cstdlib>
#include <string.h>
#include <malloc.h>

struct Kadr {
	char surname[64];
	char position[64];
	int experience;
	int category;
};

int to_count_kadrs(char* file_name) {
	FILE* file;
	file = fopen(file_name, "r");
	char* buf = new char[128];
	int count = 0;
	while (!feof(file)) {
		fgets(buf, 128, file);
		if (strchr(buf, '\n')) {
			count++;
		}
	}
	fclose(file);
	return count-1;
}

Kadr** add_kadrs(char* file_name) {
	int count_kadrs = to_count_kadrs(file_name);
	Kadr** kadrs = (Kadr**)malloc(count_kadrs * sizeof(Kadr*));
	FILE* file;
	char* buf = new char[128];
	char* tmp_str = new char[32];
	
	int kadr = 0;

	file = fopen(file_name, "r");

	while (!feof(file)) {
		int column = 0;
		int j = 0;
		Kadr* tmp_kadr = new Kadr;
		fgets(buf, 128, file);
		tmp_str[0] = '\0';
		for (int i = 0; i < strlen(buf); i++) {
			if (buf[i] != ' ' && buf[i] != '\n') {
				tmp_str[j] = buf[i];
				j++;
			}
			else {
				tmp_str[j] = '\0';
				switch (column) {
					case 0: {
						strcpy(tmp_kadr->surname, tmp_str);
						tmp_str[0] = '\0';
						break;
					}
					case 1: {
						strcpy(tmp_kadr->position, tmp_str);
						tmp_str[0] = '\0';
						break;
					}
					case 2: {
						int exp = -1;
						char *end;
						exp = strtol(tmp_str, &end, 10);
						tmp_kadr->experience = exp;
						tmp_str[0] = '\0';
						break;
					}
					case 3: {
						int category = -1;
						char *end;
						category = strtol(tmp_str, &end, 10);
						tmp_kadr->category = category;
						tmp_str[0] = '\0';
						break;
					}
				}
				j = 0;
				column++;
			}
		};
		kadrs[kadr] = tmp_kadr;
		kadr++;
	}
	fclose(file);
	return kadrs;
}

int* to_select(char* position, Kadr** kadrs, int count_kadrs) {
	int count_selected_kadrs = 0;
	for (int i = 0; i < count_kadrs;i++) {
		if (strstr(kadrs[i]->position, position)) {
			count_selected_kadrs++;
		}
	};

	int* selected_indexes = new int[count_selected_kadrs];

	selected_indexes[0] = count_selected_kadrs; // Нулевой элемент - кол-во подходящих записей
	int j = 1;
	for (int i = 0; i < count_kadrs; i++) {
		if (strstr(kadrs[i]->position, position)) {
			selected_indexes[j] = i;
			j++;
		}
	}
	return selected_indexes;
}

int main()
{
	FILE *input_file, *output_file;
	char* input_file_name = new char[32];

	setlocale(LC_ALL, "Russian");

	printf("\n Введите имя файла: ");
	gets_s(input_file_name, 32);

	input_file = fopen(input_file_name, "r");
	
	while (input_file == NULL) {
		printf("\n Файл не найден!");
		printf("\n Введите имя файла: ");
		gets_s(input_file_name, 32);
		
		input_file = fopen(input_file_name, "r");
	}
	fclose(input_file);

	Kadr** kadrs = add_kadrs(input_file_name);

	char* position = new char[32];
	printf("\n Сотрудники какой должности вас интересуют?\n (Administrator/Designer/Devoloper): ");
	gets_s(position, 32);
	printf("\n Ваш выбор: %s.", position);
	int* selected_indexes = to_select(position, kadrs, to_count_kadrs(input_file_name));

	while (selected_indexes[0] == 0) {
		printf("\n Данные записи не найдены!\n");
		printf("\n Сотрудники какой должности вас интересуют?\n (Administrator/Designer/Devoloper): ");
		gets_s(position, 32);
		printf("\n Ваш выбор: %s.", position);
		selected_indexes = to_select(position, kadrs, to_count_kadrs(input_file_name));
	}

	printf("\n Найдено элементов: %i.\n", selected_indexes[0]);

	char* output_file_name = new char[32];
	printf("\n Введите имя файла для записи: ");
	gets_s(output_file_name, 32);

	char* end_of_file = new char[8];

	int pos1 = strchr(input_file_name, '.') - input_file_name;
	int pos2 = strchr(input_file_name, '\0') - input_file_name;
	int j = 0;
	end_of_file[0] = '\0';
	for (int i = pos1; i < pos2; i++) {
		end_of_file[j] = input_file_name[i];
		j++;
		if (i == pos2 - 1) {
			end_of_file[j] = '\0';
		}
	};

	strcat(output_file_name, end_of_file);
	output_file = fopen(output_file_name, "w");

	for (int i = 0; i < selected_indexes[0]; i++) {
		char* surname = kadrs[selected_indexes[i + 1]]->surname;
		char* position = kadrs[selected_indexes[i + 1]]->position;
		int experience = kadrs[selected_indexes[i + 1]]->experience;
		int category = kadrs[selected_indexes[i + 1]]->category;
		fprintf(output_file, "%s %s %i %i\n", surname, position, experience, category);
	}

	fclose(output_file);
	printf("\n Файл создан! \n\n");
	system("pause");
}


