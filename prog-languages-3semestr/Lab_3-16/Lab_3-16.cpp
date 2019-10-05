#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Sort {
private:
	int mSize;
	int* array;
public:
	void read_file(FILE* file);
	void write_massive();
	void non_insertion_sort();
	void non_sorting_choise();
};

void Sort::read_file(FILE* file) {
	int size;

	fscanf(file, "%i", &size);
	mSize = size;
	array = (int*)malloc(mSize * sizeof(int));

	for (int i = 0; i < mSize; i++) {
		fscanf(file, "%d", &*(array + i));
	};

}

void Sort::write_massive() {
	for (int i = 0; i < mSize; i++) cout << " " << *(array + i);
	cout << endl;
}

void Sort::non_insertion_sort() {
	int a, j;
	for (int i = 1; i < mSize; i++) {
		a = *(array + i);
		j = i;
		while ((j > 0) && (*(array + (j - 1)) > a)) {
			*(array + j) = *(array + (j - 1));
			j = j - 1;
		}
		*(array + j) = a;
	}
}

void Sort::non_sorting_choise() {
	int key, k, a;
	for (int i = 0; i < mSize - 1; i++) {
		key = 0;
		k = i;
		a = *(array + i);
		for (int j = i + 1; j < mSize; j++) {
			if (*(array + j) < a) {
				k = j;
				a = *(array + j);
				key = 1;
			}
		}
		if (key) {
			*(array + k) = *(array + i);
			*(array + i) = a;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	Sort object;

	FILE* file;
	file = fopen("mas.txt", "r");
	object.read_file(file);
	fclose(file);

	cout << "\nМассив из файла: \n";
	object.write_massive();

	object.non_insertion_sort();
	cout << "\nСортировка вставками по неубывнию: \n";
	object.write_massive();

	file = fopen("mas.txt", "r");
	object.read_file(file);
	fclose(file);

	cout << "\nМассив из файла: \n";
	object.write_massive();

	object.non_sorting_choise();
	cout << "\nСортировка выбором по неубывнию: \n";
	object.write_massive();


	cout << endl;
	return 0;
}
