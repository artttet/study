#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "myscan.cpp"

class Cxor {
public:
	int x;
	Cxor(int x) {
		this->x = x;
	}
	void set_x(int x) {
		this->x = x;
	}
	int get_x() {
		return x;
	};
};

Cxor operator + (Cxor o1, Cxor o2) {
	return Cxor(o1.x ^ o2.x);
}

int read_number(double* value, const char* prompt, int size_buf, const char* mode);

void check(double* a, double* b) {
	if (*a > 255) *a = (int)*a % 256;
	if (*b > 255) *b = (int)*b % 256;
}

int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");

	double a, b, status = 0;

	do {
		status = read_number(&a, "Введите число A", 3, "int");
		if (status != 0) {
			cout << "\nПовторите попытку." << endl;
		}
	} while (status != 0);

	do {
		status = read_number(&b, "Введите число B", 3, "int");
		if (status != 0) {
			cout << "\nПовторите попытку." << endl;
		}
	} while (status != 0);

	check(&a, &b);

	Cxor obj1((int)a), obj2((int)b); 
	Cxor obj3(obj1 + obj2);

	int result = obj1.x + obj2.x + obj3.x;

	printf("\nObj1.x: %i\nObj2.x: %i\nObj3.x: %i\nСумма всего: %i\n", obj1.x, obj2.x, obj3.x, result);

}
