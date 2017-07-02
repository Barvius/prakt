// pr_10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define XM 8
#define MAX 64

int *arrp, *row, *col;

void PutTab(int k, int i, int j, int value){
	row[k] = i;
	col[k] = j;
	arrp[k] = value;
	printf("%4d(%d;  %d)\t", value, i + 1, j + 1);
}

int GetTab(int i, int j){
	int n = 0, m, xi;
	while (row[n]<i) n++;
	m = n;
	while (row[m] <= i)m++;
	for (xi = n; xi<m; xi++)
		if (col[xi] == j)
			return arrp[xi]
			;
	return 0;
}

void main(){
	setlocale(0, "rus");
	int max = 64;
	int colvo = 12 + rand() % 13;
	arrp = new int[colvo];
	row = new int[colvo];
	col = new int[colvo];
	int i, j, m = 0, z;
	int im, jm;
	for (i = 0; i<XM; i++){
		for (j = 0; j<XM; j++){
			if (m<colvo) {
				z = rand() % 100;
				if (z>MAX){
					if (z>max) { 
						max = z; 
						im = i; 
						jm = j; 
					}
					PutTab(m, i, j, z);
					m++;
				}
			}
		}
	}
	printf("\n\n");
	for (i = 0; i<XM; i++)
	{
		for (j = 0; j<XM; j++) {
			printf("%5d", GetTab(i, j));
		}
		printf("\n");
	}
	printf("\nМаксимальное %d (%d; %d)\t", max, im + 1, jm + 1);
	system("pause");
}