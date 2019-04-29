
#include "pch.h"
#include "stdio.h"
#include <locale.h>

int summ(int* M, bool modul) {
	int result = 0;
	for (int i = 0; i < 3; i++) {
		if (modul) {
			if (M[i] < 0) M[i] = 0 - M[i];
		}
		result += M[i];
	}
	return result;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int A[3], B[3], x, y;
	int result = 0;
	printf("Сейчас посчитается: Summ(|Ai|)*X + Summ(Bi)*Y \n");
	for (int i = 0; i < 3;i++) {
		printf("Введите значение элемента A[%i] \n", i);
		scanf_s("%i",&A[i]);
	}
	for (int i = 0; i < 3; i++) {
		printf("Введите значение элемента B[%i] \n", i);
		scanf_s("%i", &B[i]);
	}
	printf("Введите значение X \n");
	scanf_s("%i", &x);
	printf("Введите значение Y \n");
	scanf_s("%i", &y);
	result = summ(A, true)*x + summ(B, false)*y;

	_asm {
		mov eax, 0
		mov esi, 0
		mov ecx, 3
		lea ebx, A

			loopA:
		mov esi,[ebx]
		cmp esi, 0
		jge m1
		neg esi
		
			m1:
		add eax, esi
		add ebx,4
		loop loopA
		imul x
		mov x,eax

		mov eax,0
		lea ebx, B
		mov ecx,3 

			loopB:
		add eax, [ebx]
		add ebx,4
		loop loopB
		imul y
		add x,eax
	}
	printf("\n Результат программы на языке Ассемблер: %i \n", x);
	printf("Результат программы на языке С: %i \n", result);


}