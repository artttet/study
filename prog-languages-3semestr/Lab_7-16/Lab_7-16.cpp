#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Node {
private:
	Node* ptr;
	int index;
public:
	Node(int a, int b) {
		this->a = a;
		this->b = b;
	}
	~Node(){}
	int a;
	int b;
	
	void set_index(int index) {
		this->index = index;
	}

	int get_index() {
		return index;
	}

	void set_ptr(Node node) {
		ptr = &node;
	}

	void set_ptr(int t) {
		ptr = NULL;
	}

	Node* get_ptr() {
		return ptr;
	}

};

Node* new_array_add(Node* old_array, int count) {
	Node* new_array = (Node*)malloc((count + 1) * sizeof(Node));
	for (int i = 0; i < count - 1; i++) {
		new_array[i] = old_array[i];
	}
	return new_array;
}

Node* new_array_delete(Node* old_array, int count, int index) {
	Node* new_array = (Node*)malloc((count + 1) * sizeof(Node));
	for (int i = 0; i < count - 1; i++) {
		if (i == index || i > index) {
			if (i == count - 2) {
				break;
			}
			new_array[i] = old_array[i + 1];
			new_array[i].set_index(i);
		}
		else {
			new_array[i] = old_array[i];
		}
	}
	return new_array;
}

class List {
public:
	Node* array_node;
	Node* start;
	Node* p;
	int count;
	List(int a, int b) {
		count = 1;

		array_node = (Node*)malloc(2 * sizeof(Node));

		Node obj(a, b);
		obj.set_ptr(NULL);
		obj.set_index(count-1);
		array_node[0] = obj;


		start = &obj;
		p = &obj;

		printf("LIST --- a:%d", (*p).a);
	}
	

	void add(Node node) {
		count++;

		array_node = new_array_add(array_node, count);

		(*p).set_ptr(node);
		node.set_index(count - 1);
		node.set_ptr(NULL);
		array_node[count - 1] = node;
	}

	void del() {
		Node node(0, 0);
		int index;
		if (p != start) {
			index = (*p).get_index();
			for (int i = 0; i < count; i++) {
				if (array_node[i].get_index() == (index - 1)) {
					node = array_node[i];
				}
			}
		}
		else {
			index = 0;
			node = array_node[0];
		}
		
		
		node.set_ptr(*(*p).get_ptr());
		p = &node;

		count--;
		array_node = new_array_delete(array_node, count, index);
	}

	void print_value() {
		printf("\nPRINTVALUE --- %d\n", (*p).a);
		printf("(%d,%d)", (*p).a, (*p).b);
	}

	void change_value(int a, int b) {
		(*p).a = a;
		(*p).b = b;
	}

	void p_to_start() {
		p = start;
	}

	void p_to_right() {
		if ((*p).get_ptr() != NULL) {
			p = (*p).get_ptr();
		} else {
			p = start;
		}
	}

	void print() {
		printf("\n");
		for (int i = 0; i < count; i++) {
			if (array_node[i].get_index() == (*p).get_index()) {
				printf("[%d,%d] ", array_node[i].a, array_node[i].b);
			}
			else printf("(%d,%d) ", array_node[i].a, array_node[i].b);
		}
		printf("\n");
	}

	void find() {
		for (int i = count; i >= 0; i--) {
			int sum = array_node[i].a + array_node[i].b;
			if (sum > 0) {
				p = &array_node[i];
				break;
			}else if (i == 0) {
				printf("\nЭлементов, для которых a+b>0, в списке нет\n");
			}
			
		}
	}

};

int main() {
	setlocale(LC_ALL, "Russian");

	//int i = 213;
	//int* p = &i;
	//int t = *p;
	//printf("%i", t);
	//---------------------
	List list(10, 15);
	Node* obj = list.start;
	int a = (*obj).a;
	int key = 0;
	Node node1(10, 10);
	
	while (key != 9) {
		printf("------------------------------------------------------------------------------------------------");
		printf("\nСодержимое списка: \n");
		list.print();
		printf("1.Добавить элемент в очередь.\n");
		printf("2.Извлечь элемент из начала очереди, предварительно умножив его на среднее арифмитеское элементов очереди. \n");
		printf("3.Выход из программы.\n");
		scanf("%d", &key);

		switch (key) {
		case 1: list.add(node1);
			break;
		case 2: list.del();
			break;
		case 3: list.print_value();
			break;
		case 4: list.p_to_start();
			break;
		case 5: list.p_to_right();
			break;
		case 6: list.find();
			break;
		case 7: printf("\n%d\n", a);
		}
	}
	
}

