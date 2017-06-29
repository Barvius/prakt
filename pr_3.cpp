// pr_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(0,"rus");
	int kol_iter = 1, k = 0;
	float xn, xk, dx, eps, S=0, x, F=1;
	eps = 0.00001;
	xn = 0;
	xk = 3.14 / 2;
	dx = 3.14 / 12;
	for (float i = xn; i < xk; i+=dx) {
		printf("%1.3f \t %1.3f\n", i, sin(i));
	}
	printf("аргумент [0; pi/2]: ");
	scanf("%f", &x);
	x = sin(x);
	printf("sin(x)=%f\n", x);
	do {
		F *= 2 * k + 1;
		S += pow(-1, k)*(pow(x, 2 * k + 1) / F);
		k++;
	} while (x - S > eps);
	printf("\nСумма ряда: %f\nКоличество итераций: %d\n", S, k);
	system("pause");
	return 0;
}

