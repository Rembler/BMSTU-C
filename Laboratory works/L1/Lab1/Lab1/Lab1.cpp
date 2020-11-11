#include <locale.h> 
#include <stdio.h>
#include "Nod.h"

int main()
{
	int a, b;
	setlocale(0, "russian");
	puts("Введите два натуральных числа:");
	scanf_s("%d %d", &a, &b);
	printf("НОД %d и %d = %d.\n", a, b, nod(a, b));
	return 0;
}