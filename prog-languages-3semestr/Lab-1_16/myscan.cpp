#include <math.h>

/*
	size_buf - количество символов, которые необходимо считать
	promt - "приглашение" на ввод
	mode - может принимать "int", либо "double"
*/

int read_number(double* value, const char* prompt, const int size_buf, const char* mode) {
	size_t length = 0;
	char* end = NULL;
	char* buf = (char*)malloc(size_buf * sizeof(char));

	printf("%s: ", prompt);

	if (!fgets(buf, size_buf+2, stdin)) {
		return 1;
	}
	
	length = strlen(buf);

	if (buf[length - 1] == '\n') {
		buf[length - 1] = '\0';
		double i,f = 0, tmp_d;
		errno = 0;

		if (mode == "int") {
			tmp_d = strtod(buf, &end);
			f = modf(tmp_d, &i);
			*value = i;
		}
		if (mode == "double") {
			*value = strtod(buf, &end);
		}
		

		if (length == 1) {
			printf("Ошибка: введена пустая строка.\n");
			return 1;
		}
		if (errno != 0 || *end != '\0') {
			printf("Ошибка: некорректный символ.\n");
			printf("\t%s\n", buf);
			printf("\t%*c\n",(int)(end - buf) + 1,  '^');
			return 1;
		}
		if (f > 0) {
			printf("Ошибка: введите целое число.\n");
			return 1;
		}
	}
	else {
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Ошибка: не вводите больше чем %d символа(ов).\n", size_buf);

		return 1;
	}

	return 0;
}