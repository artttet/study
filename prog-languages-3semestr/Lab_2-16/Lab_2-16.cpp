#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "myscan.cpp"

/*
	ВНИМАНИЕ!

	Пожалуйста, не повторяйте мой способ проверки на ввод при помощи функции read_number, которая хранится в отдельном файле myscan.cpp
	Файл myscan.cpp, конечно же, желается удалить
	Всё это делается чтобы избежать палева на одинаковых лабах)

	Спасибо за внимание!
*/

int read_number(double* value, const char* prompt, int size_buf, const char* mode);

class Chisla {
private: int a, b;

public:
	void set(int a, int b);
	int getA();
	int getB();
	int multiply();
	int countOn();
	int countOff();
};

void Chisla::set(int a, int b) {
	this->a = a;
	this->b = b;
}

int Chisla::getA() {
	return a;
}

int Chisla::getB() {
	return b;
}

int Chisla::multiply() {
	return a * b;
}

int Chisla::countOn() {
	int s = 0, e = 0, count = 0;
	if (a > b) {
		s = b;
		e = a;
	}
	if (b > a) {
		s = a;
		e = b;
	}
	if (a == b)return 0;

	for (int i = s; i <= e; i++) count++;
	return count;
}

int Chisla::countOff() {
	int s = 0, e = 0, count = 0;
	if (a > b) {
		s = b;
		e = a;
	}
	if (b > a) {
		s = a;
		e = b;
	}
	if (a == b)return 0;

	for (int i = s + 1; i < e; i++) count++;
	return count;
}

int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	
	Chisla chislo;
	double a, b;
	int status = 0;

	do {
		status = read_number(&a, "Введите значение A", 6, "int");
		if (status != 0) {
			cout << "\nПопробуйте ещё раз." << endl;
		}
	} while (status != 0);

	do {
		status = read_number(&b, "Введите значение B", 6, "int");
		if (status != 0) {
			cout << "\nПопробуйте ещё раз." << endl;
		}
	} while (status != 0);

	chislo.set((int)a, (int)b);
	cout << "A = " << chislo.getA() << endl;
	cout << "B = " << chislo.getB() << endl;
	cout << "A * B = " << chislo.multiply() << endl;
	cout << "CountOn = " << chislo.countOn() << endl;
	cout << "CountOff = " << chislo.countOff() << endl;

	return 0;
}
