#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "myscan.cpp"
using namespace std;


class List {
private:
	struct Node {
		int a;
		int b;
		Node* next;
	};
	Node* start;
	Node* p;
public:
	List(int a = 0, int b = 0);
	~List();
	void add(int a, int b);
	void remove();
	void show();
	void change(int a, int b);
	void to_start();
	void step();
	void showall();
	int find();
};

List::List(int a, int b) {
	Node* node = new Node;
	node->a = a;
	node->b = b;
	node->next = NULL;
	
	start = node;
	p = node;
}

List::~List() {
	p = start;
	while (p->next != NULL) p = p->next;
	while (p != start) List::remove();
	delete start;
}

void List::add(int a, int b) {
	Node* node = new Node;
	node->a = a;
	node->b = b;
	node->next = p->next;

	p->next = node;
}

void List::remove() {
	Node* p0 = start;
	if (p0 == p) {
		
		p0 = p0->next;
		delete p;
		p = p0;
		start = p;
	}
	else {
		while (p0->next != p) p0 = p0->next;

		p0->next = p->next;
		delete p;
		p = p0;
	}
	
}

void List::show() {
	cout << endl << "(" << p->a << ", " << p->b << "); " << endl;
}

void List::change(int a, int b) {
	p->a = a;
	p->b = b;
}

void List::to_start() {
	p = start;
}

void List::step() {
	if (p->next != NULL) p = p->next;
}

void List::showall() {
	Node* p0 = start;
	
	cout << endl << "Все элементы: ";
	while (p0 != NULL) {
		if (p0 == p) {
			cout << "[" << p0->a << ", " << p0->b << "] ";
		}
		else cout << "(" << p0->a << ", " << p0->b << ") ";
		p0 = p0->next;
	}
	cout << endl;
}

/* 
	 0 - successful
	 1 - unsuccessful
*/
int List::find() {
	bool isExist = false;
	int a, b;
	Node* p0 = start;
	Node* last = new Node;

	do {
		a = p0->a;
		b = p0->b;
		if (a + b > 0) {
			last = p0;
			isExist = true;
		}
		p0 = p0->next;
	} while (p0 != NULL);

	if (isExist) {
		p = last;
		return 0;
	}
	else return 1;
}

void main_add(List* list) {
	double a, b;
	int status = 0;

	cout << endl;
	do {
		status = read_number(&a, "Введите параметр 'а'", 8, "int");
		if (status != 0) cout << "Попробуйте ещё раз." << endl;
	} while (status != 0);

	do {
		status = read_number(&b, "Введите параметр 'b'", 8, "int");
		if (status != 0) cout << "Попробуйте ещё раз." << endl;
	} while (status != 0);

	list->add(a, b);
}

void main_change(List* list) {
	double a, b;
	int status = 0;

	cout << endl;
	do {
		status = read_number(&a, "Введите параметр 'а' первого элемента", 8, "int");
		if (status != 0) cout << "Попробуйте ещё раз." << endl;
	} while (status != 0);

	do {
		status = read_number(&b, "Введите параметр 'b' первого элемента", 8, "int");
		if (status != 0) cout << "Попробуйте ещё раз." << endl;
	} while (status != 0);

	list->change(a, b);
}

void main_find(List* list) {
	if (list->find() == 0) {
		cout << endl << "Найденный элемент:" << endl;
		list->show();
		cout << endl;
	}
	else {
		cout << endl << "Элементов, для которых a + b > 0, в списке нет." << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int status = 0;
	double a, b;
	double key = 0;

	do {
		status = read_number(&a, "Введите параметр 'а' первого элемента", 8, "int");
		if (status != 0) cout << "Попробуйте ещё раз." << endl;
	} while (status != 0);

	do {
		status = read_number(&b, "Введите параметр 'b' первого элемента", 8, "int");
		if (status != 0) cout << "Попробуйте ещё раз." << endl;
	} while (status != 0);

	List list(a, b);

	while (key != 9) {
		cout << endl;
		cout << "1.Добавить элемент." << endl;
		cout << "2.Удалить элемент." << endl;
		cout << "3.Показать значения полей текущего элемента." << endl;
		cout << "4.Поменять значения полей текущего элемента." << endl;
		cout << "5.Перейти к первому элементу списка." << endl;
		cout << "6.Перейти к следующему элементу списка." << endl;
		cout << "7.Вывести все элементы списка." << endl;
		cout << "8.Найти последний элемент для которого выполняется a+b>0." << endl;
		cout << "9.Выход из программы." << endl;

		do {
			status = read_number(&key, "Выберите операцию", 1, "int");

			if(status != 0) cout << "Попробуйте ещё раз." << endl;
		} while (status != 0);

		switch ((int)key) {
		case 0: cout << endl << "А вы хитрец!" << endl;
			break;
		case 1: main_add(&list);
			break;
		case 2: list.remove();
			break;
		case 3: cout << endl << "Текущий элемент:"; list.show();
			break;
		case 4: main_change(&list);
			break;
		case 5: list.to_start();
			break;
		case 6: list.step();
			break;
		case 7: list.showall();
			break;
		case 8: main_find(&list);
			break;
		}
		


	}
	
}

