// pr_6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>

int main(){
	int A[100], n=10, tmp;
	for (int i = 0; i < n; i++) {
		A[i] = -10 + rand() % 20;
		printf("%d\t", A[i]);
	}
	printf("\n");
	bool fl = 1;
	while (fl) {
		fl = 0;
		for (int i = 0; i < n-1; i++) {
			if (A[i] > A[i+1]) {
				fl = 1;
				tmp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\t", A[i]);
	}
	system("pause");
    return 0;
}

