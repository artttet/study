
#include "pch.h"
#include <stdio.h>
#include <locale.h>

void print_bin(short chislo, char bykva) {
	printf("%c --- ", bykva);
	for (int i = 15; i >= 0;i--) {
		if (i == 11 || i == 7 || i == 3)printf(" ");
		if (chislo &(1 << i)) {
			printf("1");
		}
		else printf("0");
		
	}
}

int main(){
	setlocale(LC_ALL, "Russian");
	short a, b;
	short c = 0;

	printf("Введите число a: \n");
	scanf_s("%hi", &a);
	while (a < 0 || a > 255) {
		printf("Введите число a: \n");
		scanf_s("%hi", &a);
	}

	printf("Введите число b: \n");
	scanf_s("%hi", &b);
	while (b == 0 || b < 0|| b > 255) {
		printf("Введите число b: \n");
		scanf_s("%hi", &b);
	}
	int test= 0;
	int d = 0;
	_asm {
		mov ax, a
		cwd
		idiv b
		mov a, ax
		mov b, dx
		
		bsr esi, dx
		jz metka2
		mov d,esi

		bsr cl,dx
		inc cl
		shl ax, cl
		
		metka:
		mov esi,0
		bsr esi, dx
		bts ax, esi
		btr dx, esi

		bsr esi, dx
		jnz metka
			metka2:
			mov c, ax
		
	}
	
	printf("\n Result:\n\n A(Частное) - %hi;\n B(Остаток) - %hi;\n C - %i \n\n", a,b,c);

	print_bin(a,'A');
	printf("\n");
	print_bin(b,'B');
	printf("\n");
	print_bin(c, 'C');
	printf("\n");

}

