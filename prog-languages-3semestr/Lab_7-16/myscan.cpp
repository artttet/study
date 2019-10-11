#include <math.h>

/*
	size_buf - ���������� ��������, ������� ���������� �������
	promt - "�����������" �� ����
	mode - ����� ��������� "int", ���� "double"
*/

int read_number(double* value, const char* prompt, int size_buf, const char* mode) {
	using namespace std;

	size_t length = 0;
	char* end = NULL;
	char* buf = (char*)malloc(size_buf * sizeof(char));

	cout << prompt << ": ";

	cin.getline(buf, size_buf + 1);
	if (!cin) {
		cin.clear();
		while (cin.get() != '\n');
		cout << endl << "������: �� ������� ������ ��� " << size_buf << " �������(��)." << endl;
		return 1;
	}
	
	int tt = (strchr(buf, '\n') - buf) + 1;
	
	if (tt <= size_buf + 1) {
		double i, f = 0, tmp_d;
		errno = 0;

		if (mode == "int") {
			tmp_d = strtod(buf, &end);
			f = modf(tmp_d, &i);
			*value = i;
		}
		if (mode == "double") {
			*value = strtod(buf, &end);
		}

		if (strlen(buf) == 0) {
			cout << endl << "������: ������� ������ ������." << endl;
			return 1;
		}
		if (errno != 0 || *end != '\0') {
			cout << endl << "������: ������������ ������." << endl;
			cout << "\t" << buf << endl;
			printf("\t%*c\n",(int)(end - buf) + 1,  '^');
			return 1;
		}
		if (f > 0) {
			cout << endl << "������: ������� ����� �����." << endl;
			return 1;
		}
	}
	
	return 0;
}