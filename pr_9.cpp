// pr_9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

int *arrp, *row, *col;

void push(int i, int j, int value, int k) {
	arrp[k] = value;
	row[k] = i;
	col[k] = j;
}

int get(int i, int j) {
	int k = 0;
	while (true){
		if(row[k] == i && col[k] == j){
			return arrp[k];
			break;
		}
		if (!arrp[k]) {
			return 0;
		}
		k++;
	}
}

void main(){
	setlocale(0,"rus");
	arrp = new int[100];
	row = new int[100];
	col = new int[100];
	int a, b, k=0, val, max = 0, el, im, jm, n = 7, m = 7;
	srand(time(NULL));
	b = n;
	a = 0;
	for (int i = 0; i <= n / 2; i++) {
		for (int j = a; j < b; j++) {
			val = 1 + rand() % 8;
			push(i,j,val,k++);
			push(n - 1 - i,j, val, k++);
		}
		a++;
		b--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			el = get(i, j);
			printf("%d ", el);
			if (el>max) {
				max = el;
				im = i; jm = j;
			}
		}
		printf("\n");
	}
	printf("Максимальный элемент %d позиция %d:%d\n", max, im+1, jm+1);
	system("pause");
}