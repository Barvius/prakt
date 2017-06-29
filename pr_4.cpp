// pr_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>

void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
}

void rand(int *arr, int n) {
	for (int i = 0; i < n;i++) {
		arr[i] = -5 + rand() %10;
	}
}

float sr(int *arr, int n) {
	float S=0;
	for (int i = 0; i < n; i++) {
		S += arr[i];
	}
	return S / n;
}

int max_otr(int *arr, int n) {
	float max = 0;
	int ind;
	for (int i = 0; i < n; i++) {
		if (arr[i] < max) {
			max = arr[i];
			ind = i;
		}
	}
	arr[ind] = abs(arr[ind]);
	return max;
}

int min_pol(int *arr, int n) {
	float min = RAND_MAX;
	int ind;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min && arr[i]>0) {
			min = arr[i];
			ind = i;
		}
	}
	arr[ind] = -arr[ind];
	return min;
}

int main(){
	int X[10], n = 9;
	rand(X, n);
	print(X, n);
	printf("\n");
	printf("sr ar == %f\n",sr(X, n));
	printf("max otr == %d\n", max_otr(X, n));
	printf("min pol == %d\n", min_pol(X, n));
	print(X, n);
	printf("\n");
	printf("sr ar == %f\n", sr(X, n));
	system("pause");
    return 0;
}

