#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int *arrp, *row, *col;

void push(int i, int j, int value, int k) {
	arrp[k] = value;
	row[k] = i;
	col[k] = j;
}

int get(int i, int j) { // кто придумает как поиск и возвращение сделаать компактнее буду благодарен
	int k = 0, pos=0;
	bool w = true, e = false;
	while (w){
		if(row[k] == i && col[k] == j){
			pos = k;
			e = true;
			w = false;
		}
		if (!arrp[k]) {
			w = false;
			return 0;
		}
		k++;
	}
	if (e) {
		return arrp[pos];
	}
}

// короче для запихивания в массив функция push(i,j,val,k) где ИЖ индексы, валуе значениее соответственно, и К это номер элемента в массиве, просто каждый раз передавать на единицу больше;
// для получения значения элемента get(i,j)

void main(){
	arrp = new int[100];
	row = new int[100];
	col = new int[100];
	int arr[10][10] = {0}, n = 7, m = 7, val;
	int i, ir=0;
	int j, jr=0,a,b,k=0;
	srand(time(NULL));
	b = n;
	a = 0;
	for (i = 0; i <= n / 2; i++) {
		for (j = a; j < b; j++) {
			val = 1 + rand() % 8;
			push(i,j,val,k++);
			push(n - 1 - i,j, val, k++);
			arr[i][j] = val;
			arr[n-1-i][j] = val;
			//printf("%d %d %d == %d\n", i + 1, j + 1,ir+1, val);
		}
		a++;
		b--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", get(i,j));
		}
		printf("\n");
	}
	system("pause");
}