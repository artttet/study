
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "classes.h"

void just_count(int* count, int* b_count, int* c_count) {
	FILE* file;
	char buf[256];
	file = fopen("Input.txt", "r");
	int ccount = 0, cb_count = 0, cc_count = 0;
	while (!feof(file)) {
		fgets(buf, 256, file);
		switch (buf[0]) {
		case 'Б' : cb_count++;
			break;
		case 'К' :cc_count++;
			break;
		}
		ccount++;
	}
	*count = ccount - 1;
	*b_count = cb_count;
	*c_count = cc_count;
	fclose(file);
	
}

int main() {
	setlocale(LC_ALL, "Russian");

	FILE* file;

	int count = 0, b_count = 0, c_count = 0;
	just_count(&count, &b_count, &c_count);


	int current_year;
	char buf[256] = "";

	Finance* finances = (Finance*)malloc(count * sizeof(Finance));
	Bank* banks = (Bank*)malloc(b_count * sizeof(Bank));
	Credit* credits = (Credit*)malloc(c_count * sizeof(Credit));
	
	file = fopen("Input.txt", "r");
	
	int c = 0, cb = 0, cc = 0;
	while (!feof(file)) {
		char type = ' ';
		char* name = (char*)malloc(32*sizeof(char));
		char* owner = (char*)malloc(32 * sizeof(char));
		int yearB;
		double cp;

		fgets(buf, 256, file);
		if (c == 0) current_year = atoi(buf);
		if (c > 0) {
			sscanf_s(buf, "%c%s%s%i%lf", &type, 1, name, 32, owner, 32, &yearB, &cp);
			Finance finance(name, owner, yearB);
			finances[c - 1] = finance;

			switch (type) {
			case 'Б': {
				Bank bank(name, owner, yearB, cp);
				banks[cb] = bank;
				cb++;
				break;
			}
			case 'К' : {
				Credit credit(name, owner, yearB, cp);
				credits[cc] = credit;
				cc++;
				break;
			}
			}
		}
		c++;
	}

	FILE* f_file, * b_file, *c_file;

	f_file = fopen("Finance.txt", "w");
	for (int i = 0; i < count; i++) {
		fprintf(f_file, "%s%c", finances[i].print(), '\n');
	}
	fclose(f_file);

	b_file = fopen("Bank.txt", "w");
	for (int i = 0; i < b_count; i++) {
		fprintf(b_file, "%s%c", banks[i].print(current_year), '\n');
	}
	fclose(b_file);

	c_file = fopen("Credit.txt", "w");
	printf("%i", credits[0].yearB);
	for (int i = 0; i < c_count; i++) {
		fprintf(c_file, "%s%c", credits[i].print(current_year), '\n');
	}
	fclose(c_file);
	return 0;
}

