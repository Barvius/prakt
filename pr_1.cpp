// pr_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>

void main(){
	int n;
	float x;
	float S=0, F=1, Xn=1;
	scanf("%d %f", &n, &x);
	Xn = 1;
	for (int i = 1; i <= n; i++) {
		
		F *= i ;
		S += F / (x*Xn);
		printf("\n%f ==", Xn*x);
		printf("\n%f ===", F);
		Xn *= x + i;
		
		printf("\n%f --", S);
	}
	printf("\n%f", S);
	system("pause");
}

