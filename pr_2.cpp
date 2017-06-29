// pr_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){
	setlocale(0,"rus");
	int n = 8, m = 8;
	float A[10][10], X[10] = {0}, U = 0;
	printf("Массив по формуле\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			A[i][j] = (abs(j - 3) - 1.3)*(6.5 - j)*powf(2, j-1);
			printf("%1.f ", A[i][j]);
		}
		printf("\n");
	}
	printf("Скалярное произведение\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			X[i] += A[i][j] * A[j][i];
		}
		printf("%1.f ", X[i]);
	}
	printf("\nU = ");
	for (int i = 1; i < n; i++) {
		U += X[i] * X[n - i + 1];
	}
	printf("%1.f ", U);
	system("pause");
    return 0;
}

