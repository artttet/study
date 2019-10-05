#ifndef CLASSES_H
#define CLASSES_H



#include <cstring>

void create_str(char* str, char* name, char* owner, int year, double cp) {
	char buf[128];

	FILE* file;

	file = fopen("tmp.txt", "w");
	if (cp == -1) {
		fprintf(file, "%s %s %i", name, owner, year);
	}
	else {
		fprintf(file, "%s %s %i %7.2lf", name, owner, year, cp);
	}
	fclose(file);

	file = fopen("tmp.txt", "r");
	fgets(buf, 128, file);
	strcpy(str, buf);
	fclose(file);

	remove("tmp.txt");
}

void create_str(char* str, char* name, char* owner, char year[16], double cp) {
	char buf[128];

	FILE* file;

	file = fopen("tmp.txt", "w");
	fprintf(file, "%s %s %s %7.2lf", name, owner, year, cp);
	fclose(file);

	file = fopen("tmp.txt", "r");
	fgets(buf, 128, file);
	strcpy(str, buf);
	fclose(file);

	remove("tmp.txt");
}

class Finance {
public:
	Finance(char* name, char* owner, int yearB) {
		this->name = name;
		this->owner = owner;
		this->yearB = yearB;
	}
	char* name;
	char* owner;
	int yearB;

	char* print() {
		char* str = new char[128];
		create_str(str, name, owner, yearB, -1);
		return str;
	}

	void change_N(char* name) {
		this->name = name;
	}

	void change_O(char* owner) {
		this->owner = owner;
	}

	void change_Y(int yearB) {
		this->yearB = yearB;
	}
};

class Bank : public Finance {
public:
	Bank(char* name, char* owner, int yearB, double capital) : Finance(name, owner, yearB) {
		this->capital = capital;
	}
	double capital;

	char* print(int current_year) {
		char* str = new char[128];
		char year[16] = "";
		if (current_year < yearB) strcpy(year, "Ещё не основан");
		if ((current_year - yearB) > 15) strcpy(year, "Устойчивый");
		create_str(str, name, owner, year, capital);
		return str;
	}

	void change_C(double capital) {
		this->capital = capital;
	}
};

class Credit : public Finance {
public:
	Credit(char* name, char* owner, int yearB, double procent) : Finance(name, owner, yearB) {
		this->procent = procent;
	}
	double procent;

	char* print(int current_year) {
		char* str = new char[128];
		char year[16] = "";
		if (current_year < yearB) {
			strcpy(year, "Ещё не основан");
			create_str(str, name, owner, year, procent);
		}
		else if ((current_year - yearB) > 15) {
			strcpy(year, "Пора проверять");
			create_str(str, name, owner, year, procent);
		}
		else {
			create_str(str, name, owner, yearB, procent);
		}
		
		return str;
	}

	void change_C(double procent) {
		this->procent = procent;
	}
};

#endif